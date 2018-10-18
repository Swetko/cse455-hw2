#pragma once

#include <vector>
#include <string>
#include <chrono>

using namespace std;

void del_arg(int argc, char **argv, int index);
int find_arg(int argc, char** argv, const string& arg);
int find_int_arg(int argc, char **argv, const string& arg, int def);
float find_float_arg(int argc, char **argv, const string& arg, float def);
string find_char_arg(int argc, char **argv, const string& arg, const string& def);

extern int tests_total;
extern int tests_fail;
#define TEST(EX) do { ++tests_total; if(!(EX)) {\
    fprintf(stderr, "failed: [%s] testing [%s] in %s, line %d\n", __FUNCTION__, #EX, __FILE__, __LINE__); \
    ++tests_fail; }} while (0)



const float TEST_EPS=0.005;
inline int within_eps(float a, float b) { return a-TEST_EPS<b && b<a+TEST_EPS; }



class __ProfileScopeClass
{
unsigned long long start;
const std::string fname;
const std::string name;
int level;
int line;

static unsigned long long get_cpu_time_raw_int(void)
  {
  //struct timespec t1;
  //clock_gettime(CLOCK_REALTIME,&t1);
  //return (unsigned long long)t1.tv_sec*(unsigned long long)1000000000+(unsigned long long)t1.tv_nsec;
  long long c1=std::chrono::high_resolution_clock::now().time_since_epoch().count();
  return c1;
  }


public:


__ProfileScopeClass(int line,const std::string& fname,int level,const std::string& name="")
  :fname(fname), name(name), level(level), line(line)
  {
  start=get_cpu_time_raw_int();
  }

~__ProfileScopeClass()
  {
  if(level==1)printf("%30s(%4d) :  %lf ms\n",(name+"@"+fname).c_str(),line,double(get_cpu_time_raw_int()-start)/1e6);
  if(level==2)printf("%30s(%4d) :  %lf us\n",(name+"@"+fname).c_str(),line,double(get_cpu_time_raw_int()-start)/1e3);
  if(level==3)printf("%30s(%4d) :  %lf ns\n",(name+"@"+fname).c_str(),line,double(get_cpu_time_raw_int()-start));
  }

};

#define COMBINE1(X,Y) X##Y
#define COMBINE(X,Y) COMBINE1(X,Y)


#define TIME(...) __ProfileScopeClass COMBINE(__t,__LINE__) (__LINE__,__FUNCTION__,__VA_ARGS__);


#define NOT_IMPLEMENTED() do{static bool done=false;if(!done)fprintf(stderr,"Function \"%s\"  in file \"%s\" line %d not implemented yet!!!\n",__FUNCTION__, __FILE__, __LINE__);done=true;}while(0)
//#define NOT_IMPLEMENTED() 
