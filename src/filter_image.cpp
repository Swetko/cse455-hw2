#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "image.h"

#define M_PI 3.14159265358979323846

void Image::l1_normalize(void) { ::l1_normalize(*this); }

void l1_normalize(Image& im)
  {
  // TODO: L1-normalize the image
  
  }

Image make_box_filter(int w)
  {
  // TODO: Make a box filter
  
  return Image(1,1);
  }

Image convolve_image(const Image& im, const Image& filter, int preserve)
  {
  // TODO
  
  }

Image make_highpass_filter()
  {
  // TODO
  return Image(1,1);
  }

Image make_sharpen_filter()
  {
  // TODO
  return Image(1,1);
  }

Image make_emboss_filter()
  {
  // TODO
  return Image(1,1);
  }

// Question 2.2.1: Which of these filters should we use preserve when we run our convolution and which ones should we not? Why?
// Answer: TODO

// Question 2.2.2: Do we have to do any post-processing for the above filters? Which ones and why?
// Answer: TODO

Image make_gaussian_filter(float sigma)
  {
  // TODO
  return Image(1,1);
  }

Image add_image(const Image& a, const Image& b)
  {
  // TODO
  return Image(1,1);
  }

Image sub_image(const Image& a, const Image& b)
  {
  // TODO
  return Image(1,1);
  }

Image operator-(const Image& a, const Image& b) { return sub_image(a,b); }
Image operator+(const Image& a, const Image& b) { return add_image(a,b); }



Image make_gx_filter()
  {
  // TODO
  return Image(1,1);
  }

Image make_gy_filter()
  {
  // TODO
  return Image(1,1);
  }


void Image::feature_normalize(void) { ::feature_normalize(*this); }
void feature_normalize(Image& im)
  {
  // TODO
  // normalize each channel separately
  }

void Image::feature_normalize_total(void) { ::feature_normalize_total(*this); }
void feature_normalize_total(Image& im)
  {
  // TODO
  // normalize across all channels
  }



pair<Image,Image> sobel_image(const Image& im)
  {
  Image Mag(im.w,im.h);
  Image Theta(im.w,im.h);
  // TODO
  
  return {Mag,Theta};
  }

Image colorize_sobel(const Image& im)
  {
  // TODO
  return Image(1,1);
  }

Image bilateral_filter(const Image& im, float sigma1, float sigma2)
  {
  // TODO
  return im;
  }

