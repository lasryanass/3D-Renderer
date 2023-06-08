#include <vector>
#include <cmath>
#include <ctime>
#include <iostream>
#include "../lib/imageFormat/tgaimage.h"
#include "../lib/model/model.h"
#include "../lib/geometry/geometry.h"
#include "../lib/lineImplementation/lineImplementation.h"
#include "../lib/triangleImplementation/triangleImplementation.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);
Model *model = NULL;
const int width = 1600;
const int height = 1600;

int main(int argc, char **argv)
{
  static clock_t startTime = clock();

  model = new Model(argv[1]);

  TGAImage image(width, height, TGAImage::RGB);
  Vec3f light_dir(0, 0, -1);
  for (int i = 0; i < model->nfaces(); i++)
  {
    std::vector<int> face = model->face(i);
    Vec2i screen_coords[3];
    Vec3f world_coords[3];
    for (int j = 0; j < 3; j++)
    {
      Vec3f v = model->vert(face[j]);
      screen_coords[j] = Vec2i((v.x + 1.) * width / 2., (v.y + 1.) * height / 2.);
      world_coords[j] = v;
    }
    Vec3f n = (world_coords[2] - world_coords[0]) ^ (world_coords[1] - world_coords[0]);
    n.normalize();
    float intensity = n * light_dir;
    if (intensity > 0)
    {
      triangle(screen_coords[0], screen_coords[1], screen_coords[2], image, TGAColor(intensity * 255, intensity * 255, intensity * 255, 255));
    }
  }
  clock_t endTime = clock();
  std::cout << "Time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
  image.flip_vertically();
  image.write_tga_file("rasterized.tga");
  delete model;
  return 0;
}
