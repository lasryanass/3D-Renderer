(()=>{"use strict";var e={81:e=>{e.exports=require("child_process")}},t={};function r(n){var a=t[n];if(void 0!==a)return a.exports;var o=t[n]={exports:{}};return e[n](o,o.exports,r),o.exports}r.n=e=>{var t=e&&e.__esModule?()=>e.default:()=>e;return r.d(t,{a:t}),t},r.d=(e,t)=>{for(var n in t)r.o(t,n)&&!r.o(e,n)&&Object.defineProperty(e,n,{enumerable:!0,get:t[n]})},r.o=(e,t)=>Object.prototype.hasOwnProperty.call(e,t),(()=>{const e=require("react");var t=r.n(e);const n=require("react-dom/client");var a=r.n(n);function o(e,t){(null==t||t>e.length)&&(t=e.length);for(var r=0,n=new Array(t);r<t;r++)n[r]=e[r];return n}function c(e,t){return function(e){if(Array.isArray(e))return e}(e)||function(e,t){var r=null==e?null:"undefined"!=typeof Symbol&&e[Symbol.iterator]||e["@@iterator"];if(null!=r){var n,a,o,c,i=[],s=!0,l=!1;try{if(o=(r=r.call(e)).next,0===t){if(Object(r)!==r)return;s=!1}else for(;!(s=(n=o.call(r)).done)&&(i.push(n.value),i.length!==t);s=!0);}catch(d){l=!0,a=d}finally{try{if(!s&&null!=r.return&&(c=r.return(),Object(c)!==c))return}finally{if(l)throw a}}return i}}(e,t)||function(e,t){if(e){if("string"===typeof e)return o(e,t);var r=Object.prototype.toString.call(e).slice(8,-1);return"Object"===r&&e.constructor&&(r=e.constructor.name),"Map"===r||"Set"===r?Array.from(e):"Arguments"===r||/^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(r)?o(e,t):void 0}}(e,t)||function(){throw new TypeError("Invalid attempt to destructure non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method.")}()}const i=require("react/jsx-runtime");const s=function(t){var r=t.onFileDrop,n=c((0,e.useState)(!1),2),a=n[0],o=n[1];return(0,i.jsx)("div",{className:a?"bg-[#59b7c3] transition rounded-lg":" transition cursor-pointer mx-auto",onDragEnter:function(e){e.preventDefault(),o(!0)},onDragLeave:function(){o(!1)},onDragOver:function(e){e.preventDefault()},onDrop:function(e){e.preventDefault(),o(!1);var t=e.dataTransfer.files[0].path;document.getElementById("path").value=t,r(t)},children:(0,i.jsx)("svg",{fill:"#05727a",height:"220px",width:"220px",version:"1.1",id:"Capa_1",xmlns:"http://www.w3.org/2000/svg",viewBox:"0 0 490.955 490.955",children:(0,i.jsx)("path",{id:"XMLID_448_",d:"M445.767,308.42l-53.374-76.49v-20.656v-11.366V97.241c0-6.669-2.604-12.94-7.318-17.645L312.787,7.301\r C308.073,2.588,301.796,0,295.149,0H77.597C54.161,0,35.103,19.066,35.103,42.494V425.68c0,23.427,19.059,42.494,42.494,42.494\r h159.307h39.714c1.902,2.54,3.915,5,6.232,7.205c10.033,9.593,23.547,15.576,38.501,15.576c26.935,0-1.247,0,34.363,0\r c14.936,0,28.483-5.982,38.517-15.576c11.693-11.159,17.348-25.825,17.348-40.29v-40.06c16.216-3.418,30.114-13.866,37.91-28.811\r C459.151,347.704,457.731,325.554,445.767,308.42z M170.095,414.872H87.422V53.302h175.681v46.752\r c0,16.655,13.547,30.209,30.209,30.209h46.76v66.377h-0.255v0.039c-17.685-0.415-35.529,7.285-46.934,23.46l-61.586,88.28\r c-11.965,17.134-13.387,39.284-3.722,57.799c7.795,14.945,21.692,25.393,37.91,28.811v19.842h-10.29H170.095z M410.316,345.771\r c-2.03,3.866-5.99,6.271-10.337,6.271h-0.016h-32.575v83.048c0,6.437-5.239,11.662-11.659,11.662h-0.017H321.35h-0.017\r c-6.423,0-11.662-5.225-11.662-11.662v-83.048h-32.574h-0.016c-4.346,0-8.308-2.405-10.336-6.271\r c-2.012-3.866-1.725-8.49,0.783-12.07l61.424-88.064c2.189-3.123,5.769-4.984,9.57-4.984h0.017c3.802,0,7.38,1.861,9.568,4.984\r l61.427,88.064C412.04,337.28,412.328,341.905,410.316,345.771z"})})})},l=require("electron-is-packaged");const d=function(){var t=c((0,e.useState)(!1),2),n=t[0],a=t[1],o=c((0,e.useState)(null),2),d=o[0],u=o[1],m=function(e){(0,r(81).spawn)(".\\bin\\convert.exe",[".\\outputs\\".concat(1===e?"lines.tga":"rasterized.tga")]).on("close",(function(e){0===e?function(){if(u(null),l.isPackaged){var e=process.resourcesPath.replace(/\\resources$/,"/output.png");u(e)}}():a("Child process exited with code ".concat(e))}))};return(0,i.jsxs)("div",{className:"w-full h-full",children:[(0,i.jsx)("header",{className:"text-[#21565a] text-center font-medium text-2xl mt-6",children:"Native 3D renderer written in c++"}),d?(0,i.jsxs)(i.Fragment,{children:[(0,i.jsx)("img",{src:d,className:"w-72 h-72 rotate-180 mx-auto my-10",alt:"rendered image"}),(0,i.jsx)("button",{onClick:function(){return u(null)},className:"relative shadow-md md:hover:shadow-lg w-1/3 mx-auto flex justify-center p-2 md:py-3 text-sm md:text-base font-medium rounded-md text-white bg-[#05727a] md:hover:bg-[#055d65] md:px-6 active:scale-95 transition",children:"Return"})]}):(0,i.jsxs)(i.Fragment,{children:[(0,i.jsx)("div",{className:"w-screen flex items-center justify-center h-[60vh]",children:(0,i.jsx)(s,{})}),(0,i.jsx)("div",{className:"flex items-center mb-4 w-2/3 mx-auto",children:(0,i.jsx)("div",{className:"border-b border-gray-300 focus-within:border-[#05727a] w-full",children:(0,i.jsx)("input",{type:"path",name:"path",id:"path",required:!0,className:"block w-full border-0 h-10 border-b border-transparent px-4 bg-gray-50 focus:border-tertiary focus:ring-0",placeholder:"path to file"})})}),(0,i.jsx)(i.Fragment,{children:n&&(0,i.jsx)("div",{className:"text-red-500 mx-auto w-2/3 bg-red-100 border-2 border-red-500 font-medium text-center",children:n})}),(0,i.jsxs)("div",{className:"flex items-center space-x-6 justify-center w-2/3 mx-auto",children:[(0,i.jsx)("button",{onClick:function(){(0,r(81).spawn)(".\\bin\\drawline.exe",[document.getElementById("path").value.replace(/\\/g,"\\\\")]).on("close",(function(e){0===e?m(1):a("Child process exited with code ".concat(e))}))},className:"relative shadow-md md:hover:shadow-lg w-full flex justify-center p-2 md:py-3 text-sm md:text-base font-medium rounded-md text-white bg-[#05727a] md:hover:bg-[#055d65] md:px-6 active:scale-95 transition",children:"Render Lines"}),(0,i.jsx)("button",{onClick:function(){(0,r(81).spawn)(".\\bin\\rasterize",[document.getElementById("path").value.replace(/\\/g,"\\\\")]).on("close",(function(e){0===e?m(2):a("Child process exited with code ".concat(e))}))},className:" w-full flex justify-center p-2 md:py-3 text-sm md:text-base font-medium rounded-md text-[#21565a] bg-[#b3e5ec] md:hover:text-white md:hover:bg-[#59b7c3] md:px-6 active:scale-95 transition",children:"Rasterize"}),(0,i.jsx)("button",{onClick:function(){(0,r(81).spawn)(".\\bin\\triangulate.exe",[document.getElementById("path").value.replace(/\\/g,"\\\\")]).on("close",(function(e){if(0===e){var t=process.resourcesPath.replace(/\\resources$/,"/output.obj");document.getElementById("path").value=t}else a("Child process exited with code ".concat(e))}))},className:"relative shadow-md md:hover:shadow-lg w-1/3 mx-auto flex justify-center p-2 md:py-3 text-sm md:text-base font-medium rounded-md text-white bg-[#05727a] md:hover:bg-[#055d65] md:px-6 active:scale-95 transition",children:"Triangulate"})]})]})]})};a().createRoot(document.getElementById("root")).render((0,i.jsx)(t().StrictMode,{children:(0,i.jsx)(d,{})}))})()})();
//# sourceMappingURL=main.042c8386.js.map