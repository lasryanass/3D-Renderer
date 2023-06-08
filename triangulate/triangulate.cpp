#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Vertex
{
  float x, y, z;
};

struct Face
{
  std::vector<int> vertexIndices;
  std::vector<int> normalIndices;
  std::vector<int> texCoordIndices;
};

void triangulateObjFile(const std::string &inputPath, const std::string &outputPath)
{
  std::ifstream inputFile(inputPath);
  if (!inputFile.is_open())
  {
    std::cerr << "Failed to open input file: " << inputPath << std::endl;
    return;
  }

  std::ofstream outputFile(outputPath);
  if (!outputFile.is_open())
  {
    std::cerr << "Failed to open output file: " << outputPath << std::endl;
    return;
  }

  std::vector<Vertex> vertices;
  std::vector<Vertex> normals;
  std::vector<Vertex> texCoords;
  std::vector<Face> faces;

  std::string line;
  while (std::getline(inputFile, line))
  {
    std::istringstream iss(line);
    std::string prefix;
    iss >> prefix;

    if (prefix == "v")
    {
      Vertex vertex;
      iss >> vertex.x >> vertex.y >> vertex.z;
      vertices.push_back(vertex);
      outputFile << line << "\n"; // Preserve vertices in the output file
    }
    else if (prefix == "vn")
    {
      Vertex normal;
      iss >> normal.x >> normal.y >> normal.z;
      normals.push_back(normal);
      outputFile << line << "\n"; // Preserve vertex normals in the output file
    }
    else if (prefix == "vt")
    {
      Vertex texCoord;
      iss >> texCoord.x >> texCoord.y;
      texCoords.push_back(texCoord);
      outputFile << line << "\n"; // Preserve texture coordinates in the output file
    }
    else if (prefix == "f")
    {
      Face face;

      std::string vertexStr;
      while (iss >> vertexStr)
      {
        std::istringstream viss(vertexStr);
        std::string vertexIndexStr, texCoordIndexStr, normalIndexStr;
        std::getline(viss, vertexIndexStr, '/');
        std::getline(viss, texCoordIndexStr, '/');
        std::getline(viss, normalIndexStr, '/');

        int vertexIndex = std::stoi(vertexIndexStr);
        int texCoordIndex = (texCoordIndexStr.empty()) ? -1 : std::stoi(texCoordIndexStr);
        int normalIndex = (normalIndexStr.empty()) ? -1 : std::stoi(normalIndexStr);

        face.vertexIndices.push_back(vertexIndex);
        face.texCoordIndices.push_back(texCoordIndex);
        face.normalIndices.push_back(normalIndex);
      }

      faces.push_back(face);
    }
    else
    {
      // Preserve other lines in the same format
      outputFile << line << "\n";
    }
  }

  inputFile.close();

  for (const auto &face : faces)
  {
    if (face.vertexIndices.size() == 3)
    {
      // Triangle face, write as is
      outputFile << "f ";
      for (size_t i = 0; i < face.vertexIndices.size(); ++i)
      {
        int vertexIndex = face.vertexIndices[i];
        int texCoordIndex = face.texCoordIndices[i];
        int normalIndex = face.normalIndices[i];

        outputFile << vertexIndex;

        if (texCoordIndex != -1)
          outputFile << "/" << texCoordIndex;

        if (normalIndex != -1)
          outputFile << "/" << normalIndex;

        outputFile << " ";
      }
      outputFile << "\n";
    }
    else if (face.vertexIndices.size() > 3)
    {
      // Polygon face, triangulate
      int v0 = face.vertexIndices[0];
      int t0 = face.texCoordIndices[0];
      int n0 = face.normalIndices[0];

      for (size_t i = 1; i < face.vertexIndices.size() - 1; ++i)
      {
        int v1 = face.vertexIndices[i];
        int t1 = face.texCoordIndices[i];
        int n1 = face.normalIndices[i];

        int v2 = face.vertexIndices[i + 1];
        int t2 = face.texCoordIndices[i + 1];
        int n2 = face.normalIndices[i + 1];

        outputFile << "f " << v0;
        if (t0 != -1)
          outputFile << "/" << t0;
        if (n0 != -1)
          outputFile << "/" << n0;

        outputFile << " " << v1;
        if (t1 != -1)
          outputFile << "/" << t1;
        if (n1 != -1)
          outputFile << "/" << n1;

        outputFile << " " << v2;
        if (t2 != -1)
          outputFile << "/" << t2;
        if (n2 != -1)
          outputFile << "/" << n2;

        outputFile << "\n";
      }
    }
  }

  outputFile.close();
}

int main(int argc, char **argv)
{
  std::string inputPath = argv[1];
  std::string outputPath = "output.obj";

  triangulateObjFile(inputPath, outputPath);

  return 0;
}
