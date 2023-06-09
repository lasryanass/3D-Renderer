#include <vector>
#include <cmath>
#include "../imageFormat/tgaimage.h"
#include "../model/model.h"
#include "../geometry/geometry.h"

void triangle(Vec2i t0, Vec2i t1, Vec2i t2, TGAImage &image, TGAColor color)
{
  if (t0.y == t1.y && t0.y == t2.y)
    return;
  if (t0.y > t1.y)
    std::swap(t0, t1);
  if (t0.y > t2.y)
    std::swap(t0, t2);
  if (t1.y > t2.y)
    std::swap(t1, t2);
  int total_height = t2.y - t0.y;
  for (int i = 0; i < total_height; i++)
  {
    bool second_half = i > t1.y - t0.y || t1.y == t0.y;
    int segment_height = second_half ? t2.y - t1.y : t1.y - t0.y;
    float alpha = (float)i / total_height;
    float beta = (float)(i - (second_half ? t1.y - t0.y : 0)) / segment_height;
    Vec2i A = t0 + (t2 - t0) * alpha;
    Vec2i B = second_half ? t1 + (t2 - t1) * beta : t0 + (t1 - t0) * beta;
    if (A.x > B.x)
      std::swap(A, B);
    for (int j = A.x; j <= B.x; j++)
    {
      image.set(j, t0.y + i, color);
    }
  }
}
