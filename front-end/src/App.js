import { useState } from "react";
import DragAndDrop from "./components/DragnDrop";
import { isPackaged } from "electron-is-packaged";

function App() {
  const [error, setError] = useState(false);
  const [displayImage, setDisplayImage] = useState(null);
  const loadImg = () => {
    setDisplayImage(null);
    if (!isPackaged) {
      return;
    }
    const filePath = process.resourcesPath.replace(
      /\\resources$/,
      "/output.png"
    );

    setDisplayImage(filePath);
  };

  const renderLines = () => {
    const { spawn } = require("child_process");

    const command = ".\\bin\\drawline.exe";
    const path = document.getElementById("path").value.replace(/\\/g, "\\\\");
    const args = [path];

    const child = spawn(command, args);

    child.on("close", (code) => {
      if (code === 0) {
        convertimg(1);
      } else {
        setError(`Child process exited with code ${code}`);
      }
    });
  };
  const triangulate = () => {
    const { spawn } = require("child_process");

    const command = ".\\bin\\triangulate.exe";
    const path = document.getElementById("path").value.replace(/\\/g, "\\\\");
    const args = [path];

    const child = spawn(command, args);

    child.on("close", (code) => {
      if (code === 0) {
        const filePath = process.resourcesPath.replace(
          /\\resources$/,
          "/output.obj"
        );
        document.getElementById("path").value = filePath;
      } else {
        setError(`Child process exited with code ${code}`);
      }
    });
  };

  const convertimg = (parameter) => {
    const { spawn } = require("child_process");

    const command = ".\\bin\\convert.exe";
    const args = [
      `.\\outputs\\${parameter === 1 ? "lines.tga" : "rasterized.tga"}`,
    ];

    const child = spawn(command, args);

    child.on("close", (code) => {
      if (code === 0) {
        loadImg();
      } else {
        setError(`Child process exited with code ${code}`);
      }
    });
  };
  const rasterize = () => {
    const { spawn } = require("child_process");

    const command = ".\\bin\\rasterize";
    const path = document.getElementById("path").value.replace(/\\/g, "\\\\");
    const args = [path];

    const child = spawn(command, args);

    child.on("close", (code) => {
      if (code === 0) {
        convertimg(2);
      } else {
        setError(`Child process exited with code ${code}`);
      }
    });
  };

  return (
    <div className="w-full h-full">
      <header className="text-[#21565a] text-center font-medium text-2xl mt-6">
        Native 3D renderer written in c++
      </header>
      {displayImage ? (
        <>
          <img
            src={displayImage}
            className="w-72 h-72 rotate-180 mx-auto my-10"
            alt="rendered image"
          />
          <button
            onClick={() => setDisplayImage(null)}
            className="relative shadow-md md:hover:shadow-lg w-1/3 mx-auto flex justify-center p-2 md:py-3 text-sm md:text-base font-medium rounded-md text-white bg-[#05727a] md:hover:bg-[#055d65] md:px-6 active:scale-95 transition"
          >
            Return
          </button>
        </>
      ) : (
        <>
          <div className="w-screen flex items-center justify-center h-[60vh]">
            <DragAndDrop />
          </div>

          <div className="flex items-center mb-4 w-2/3 mx-auto">
            <div className="border-b border-gray-300 focus-within:border-[#05727a] w-full">
              <input
                type="path"
                name="path"
                id="path"
                required
                className="block w-full border-0 h-10 border-b border-transparent px-4 bg-gray-50 focus:border-tertiary focus:ring-0"
                placeholder="path to file"
              />
            </div>
          </div>
          <>
            {error && (
              <div className="text-red-500 mx-auto w-2/3 bg-red-100 border-2 border-red-500 font-medium text-center">
                {error}
              </div>
            )}
          </>
          <div className="flex items-center space-x-6 justify-center w-2/3 mx-auto">
            <button
              onClick={renderLines}
              className="relative shadow-md md:hover:shadow-lg w-full flex justify-center p-2 md:py-3 text-sm md:text-base font-medium rounded-md text-white bg-[#05727a] md:hover:bg-[#055d65] md:px-6 active:scale-95 transition"
            >
              Render Lines
            </button>
            <button
              onClick={rasterize}
              className=" w-full flex justify-center p-2 md:py-3 text-sm md:text-base font-medium rounded-md text-[#21565a] bg-[#b3e5ec] md:hover:text-white md:hover:bg-[#59b7c3] md:px-6 active:scale-95 transition"
            >
              Rasterize
            </button>
            <button
              onClick={triangulate}
              className="relative shadow-md md:hover:shadow-lg w-1/3 mx-auto flex justify-center p-2 md:py-3 text-sm md:text-base font-medium rounded-md text-white bg-[#05727a] md:hover:bg-[#055d65] md:px-6 active:scale-95 transition"
            >
              Triangulate
            </button>
          </div>
        </>
      )}
    </div>
  );
}
export default App;
