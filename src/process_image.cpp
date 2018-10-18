#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>

#include "image.h"

using namespace std;


Image rgb_to_grayscale(const Image& im)
  {
  // TODO Fill this in
  NOT_IMPLEMENTED();
  return Image(1,1);
  }

void shift_image(Image& im, int c, float v)
  {
  // TODO Fill this in
  NOT_IMPLEMENTED();
  }

void scale_image(Image& im, int c, float v)
  {
  // TODO Fill this in
  NOT_IMPLEMENTED();
  }

void clamp_image(Image& im)
  {
  // TODO Fill this in
  NOT_IMPLEMENTED();
  }

void Image::clamp(void) { clamp_image(*this); }
void Image::shift(int c, float v) { shift_image(*this,c,v); }
void Image::scale(int c, float v) { scale_image(*this,c,v); }


// These might be handy
float three_way_max(float a, float b, float c)
  {
  return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
  }

float three_way_min(float a, float b, float c)
  {
  return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
  }

void rgb_to_hsv(Image& im)
  {
  // TODO Fill this in
  NOT_IMPLEMENTED();
  }

void hsv_to_rgb(Image& im)
  {
  // TODO Fill this in
  NOT_IMPLEMENTED();
  }


struct RGBcolor { float r,g,b; };
struct XYZcolor { float x,y,z; };
struct LCHcolor { float l,c,h; };

float l2g(float a)
  {
  if(a<0.0031308)return 12.92*a;
  else return 1.055*powf(a,1.0f/2.4f)-0.055;
  }

float g2l(float a)
  {
  if(a<0.04045)return a/12.92;
  else return powf((a+0.055f)/1.055f,2.4f);
  }

RGBcolor linear2gamma(RGBcolor a)
  {
  a.r=l2g(a.r);
  a.g=l2g(a.g);
  a.b=l2g(a.b);
  return a;
  }

RGBcolor gamma2linear(RGBcolor a)
  {
  a.r=g2l(a.r);
  a.g=g2l(a.g);
  a.b=g2l(a.b);
  return a;
  }

XYZcolor toXYZ(RGBcolor a)
  {
  XYZcolor b;
  a=gamma2linear(a);
  b.x=0.412383*a.r+0.357585*a.g+0.18048  *a.b;
  b.y=0.212635*a.r+0.71517 *a.g+0.072192 *a.b;
  b.z=0.01933 *a.r+0.119195*a.g+0.950528 *a.b;
  return b;
  }


RGBcolor toRGB(XYZcolor a)
  {
  RGBcolor b;
  b.r=(3.24103  )*a.x+(-1.53741 )*a.y +(-0.49862 )*a.z;
  b.g=(-0.969242)*a.x+(1.87596  )*a.y +(0.041555 )*a.z;
  b.b=(0.055632 )*a.x+(-0.203979)*a.y +(1.05698  )*a.z;
  b=linear2gamma(b);
  return b;
  }

LCHcolor rgb2lch(RGBcolor a)
  {
  LCHcolor b={0.f,0.f,0.f};
  XYZcolor c=toXYZ(a);
  
  if(c.x==0.f && c.y==0.f && c.z==0.f)return b;
  
  
  float u1=4*c.x/(1*c.x+15*c.y+3*c.z);
  float v1=9*c.y/(1*c.x+15*c.y+3*c.z);
  
  
  float un=0.2009;
  float vn=0.4610;
  
  float cutoff=powf(6.f/29.f,3);
  
  float l=0;
  if(c.y<=cutoff)l=powf(29.f/3.f,3)*c.y;
  else l=116.f*powf(c.y,1.f/3.f)-16.f;
  float u=13.f*l*(u1-un);
  float v=13.f*l*(v1-vn);
  
  
  b.l=l;
  b.c=sqrtf(u*u+v*v);
  b.h=atan2f(u,v);
  
  return b;
  }

RGBcolor lch2rgb(LCHcolor a)
  {
  XYZcolor b={0.f,0.f,0.f};
  
  if(a.l==0.f && a.c==0.f && a.h==0.f)return toRGB(b);
  
  float u=a.c*sinf(a.h);
  float v=a.c*cosf(a.h);
  float l=a.l;
  
  
  
  float un=0.2009;
  float vn=0.4610;
  
  float cutoff=8;
  
  
  float u1=u/(13.f*l)+un;
  float v1=v/(13.f*l)+vn;
  
  if(l<=cutoff)b.y=l*powf(3.f/29.f,3);
  else b.y=powf((l+16.f)/116.f,3);
  
  b.x=b.y*(9*u1)/(4*v1);
  b.z=b.y*(12-3*u1-20*v1)/(4*v1);
  
  //printf("xyz2   %f %f %f\n",b.x,b.y,b.z);
  
  return toRGB(b);
  }


void rgb_to_lch(Image& im)
  {
  // TODO Fill this in
  NOT_IMPLEMENTED();
  }

void lch_to_rgb(Image& im)
  {
  // TODO Fill this in
  NOT_IMPLEMENTED();
  
  }

void Image::HSVtoRGB(void) { hsv_to_rgb(*this); }
void Image::RGBtoHSV(void) { rgb_to_hsv(*this); }
void Image::LCHtoRGB(void) { lch_to_rgb(*this); }
void Image::RGBtoLCH(void) { rgb_to_lch(*this); }
