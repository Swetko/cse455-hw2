#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "utils.h"
#include "image.h"

int tests_total = 0;
int tests_fail = 0;

int same_image(const Image& a, const Image& b) { return a==b; }

bool operator ==(const Image& a, const Image& b)
  {
  if(a.w != b.w || a.h != b.h || a.c != b.c) 
    {
    printf("Expected %d x %d x %d image, got %d x %d x %d\n", b.w, b.h, b.c, a.w, a.h, a.c);
    return 0;
    }
  
  for(int i = 0; i < a.w*a.h*a.c; ++i) if(!within_eps(a.data[i], b.data[i])) 
    {
    printf("The value at %d %d %d should be %f, but it is %f! \n", i/(a.w*a.h), (i%(a.w*a.h))/a.h, (i%(a.w*a.h))%a.h, b.data[i], a.data[i]);
    return 0;
    }
  return 1;
  }



void del_arg(int argc, char **argv, int index)
{
    int i;
    for(i = index; i < argc-1; ++i) argv[i] = argv[i+1];
    argv[i] = 0;
}

int find_arg(int argc, char** argv, const string& arg)
{
    int i;
    for(i = 0; i < argc; ++i) {
        if(!argv[i]) continue;
        if(argv[i]==arg) {
            del_arg(argc, argv, i);
            return 1;
        }
    }
    return 0;
}

int find_int_arg(int argc, char **argv, const string& arg, int def)
{
    int i;
    for(i = 0; i < argc-1; ++i){
        if(!argv[i]) continue;
        if(argv[i]==arg) {
            def = atoi(argv[i+1]);
            del_arg(argc, argv, i);
            del_arg(argc, argv, i);
            break;
        }
    }
    return def;
}

float find_float_arg(int argc, char **argv, const string& arg, float def)
{
    int i;
    for(i = 0; i < argc-1; ++i){
        if(!argv[i]) continue;
        if(argv[i]==arg) {
            def = atof(argv[i+1]);
            del_arg(argc, argv, i);
            del_arg(argc, argv, i);
            break;
        }
    }
    return def;
}

string find_char_arg(int argc, char **argv, const string& arg, const string& def)
{
    int i;
    string ret=def;
    for(i = 0; i < argc-1; ++i){
        if(!argv[i]) continue;
        if(argv[i]==arg) {
            ret = argv[i+1];
            del_arg(argc, argv, i);
            del_arg(argc, argv, i);
            break;
        }
    }
    return ret;
}







