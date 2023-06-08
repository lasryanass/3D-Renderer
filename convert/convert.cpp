#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include <vector>
#include <fstream>
#include "stb_image.h"
#include "stb_image_write.h"

void convertTgaToPng(const std::string &tgaPath, const std::string &pngPath)
{
  int width, height, numChannels;
  unsigned char *image = stbi_load(tgaPath.c_str(), &width, &height, &numChannels, 0);
  if (image == nullptr)
  {
    std::cerr << "Failed to load TGA file: " << tgaPath << std::endl;
    return;
  }

  std::vector<unsigned char> flippedImage(width * height * numChannels);
  for (int y = 0; y < height; ++y)
  {
    for (int x = 0; x < width; ++x)
    {
      for (int c = 0; c < numChannels; ++c)
      {
        flippedImage[(height - 1 - y) * width * numChannels + x * numChannels + c] =
            image[y * width * numChannels + x * numChannels + c];
      }
    }
  }

  int result = stbi_write_png(pngPath.c_str(), width, height, numChannels, flippedImage.data(), width * numChannels);
  if (result == 0)
  {
    std::cerr << "Failed to write PNG file: " << pngPath << std::endl;
    stbi_image_free(image);
    return;
  }

  stbi_image_free(image);

  std::cout << "TGA to PNG conversion completed!" << std::endl;
}

int main(int argc, char **argv)
{
  std::string tgaPath = argv[1];
  std::string pngPath = "output.png";

  convertTgaToPng(tgaPath, pngPath);

  return 0;
}
