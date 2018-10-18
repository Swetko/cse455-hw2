#include <cmath>
#include "image.h"

using namespace std;

float Image::nn_interpolate(float x, float y, int c) const
  {
  // TODO Fill in
  NOT_IMPLEMENTED();
  return 0;
  }

float Image::bilinear_interpolate(float x, float y, int c) const
  {
  // TODO Fill in
  NOT_IMPLEMENTED();
  return 0;
  }

float bilinear_interpolate(const Image& im, float x, float y, int c) { return im.bilinear_interpolate(x,y,c); }
float       nn_interpolate(const Image& im, float x, float y, int c) { return im.nn_interpolate(x,y,c); }

Image nn_resize(const Image& im, int w, int h)
  {
  // TODO Fill in
  NOT_IMPLEMENTED();
  
  return Image(1,1,1);
  }



Image bilinear_resize(const Image& im, int w, int h)
  {
  // TODO Fill in
  NOT_IMPLEMENTED();
  
  return Image(1,1,1);
  }


