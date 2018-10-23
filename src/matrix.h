#pragma once

#include <cassert>

struct Matrix
  {
  int rows, cols;
  double* data;
  
  // constructor
  Matrix() : Matrix(0,0) {}
  Matrix(int rows, int cols=1) : rows(rows), cols(cols), data(nullptr) { if(rows*cols)data=(double*)calloc(rows*cols,sizeof(double)); }
  
  // destructor
  ~Matrix() { free(data); }
  
  // copy constructor
  Matrix(const Matrix& a) : data(nullptr) { *this=a; }
  
  // move constructor
  Matrix(Matrix&& a)  : data(nullptr) { *this=move(a); }
  
  // copy assignment
  Matrix& operator=(const Matrix& a)
    {
    if(this==&a)return *this;
    
    if(data){free(data);data=nullptr;}
    rows=a.rows;
    cols=a.cols;
    data=(double*)calloc(rows*cols,sizeof(double));
    memcpy(data,a.data,sizeof(double)*rows*cols);
    return *this;
    }
  
  // move assignment
  Matrix& operator=(Matrix&& a)
    {
    if(this==&a)return *this;
    
    if(data)free(data);
    
    rows=a.rows;
    cols=a.cols;
    data=a.data;
    
    a.data=nullptr;
    return *this;
    }
  
  // access
  
        double* operator[](int a)       { return data+cols*a; }
  const double* operator[](int a) const { return data+cols*a; }
  
        double& operator()(int row,int col)       { return data[cols*row+col]; }
  const double& operator()(int row,int col) const { return data[cols*row+col]; }
  
  
  // vector access
        double& operator()(int n)       { assert(cols==1 || rows==1); return data[n]; }
  const double& operator()(int n) const { assert(cols==1 || rows==1); return data[n]; }
  
  
  // Create matrix
  
  static Matrix identity_homography(void);
  static Matrix translation_homography(double dx, double dy);
  static Matrix augment(const Matrix& m);
  static Matrix identity(int rows, int cols);
  
  // print matrix
  void print(void) const;
  
  // transform matrix
  
  Matrix inverse(void) const;
  Matrix transpose(void) const;
  
  
  };

inline Matrix operator*(const Matrix& a,const Matrix& b)
  {
  assert(a.cols == b.rows);
  Matrix p(a.rows, b.cols);
  for(int i = 0; i < p.rows;i++)
      for(int j = 0; j < p.cols;j++)
          for(int k = 0; k < a.cols;k++)
              p(i,j) += a(i,k)*b(k,j);
  return p;
  }

inline Matrix operator-(const Matrix& a,const Matrix& b)
  {
  assert(a.cols == b.cols);
  assert(a.rows == b.rows);
  Matrix p(a.rows, a.cols);
  for(int i = 0; i < p.rows;i++)
    for(int j = 0; j < p.cols;j++)
      p(i,j) = a(i,j) - b(i,j);
  return p;
  }

inline Matrix operator+(const Matrix& a,const Matrix& b)
  {
  assert(a.cols == b.cols);
  assert(a.rows == b.rows);
  Matrix p(a.rows, a.cols);
  for(int i = 0; i < p.rows;i++)
    for(int j = 0; j < p.cols;j++)
      p(i,j) = a(i,j) + b(i,j);
  return p;
  }

inline Matrix operator*(double scale, const Matrix& a)
  {
  Matrix b=a;
  for(int q1=0;q1<a.rows;q1++)for(int q2=0;q2<a.cols;q2++)b(q1,q2)*=scale;
  return b;
  }

inline Matrix operator*(const Matrix& a, double scale) { return scale*a;}




void print_matrix(const Matrix &m);
Matrix LUP_solve(const Matrix& L, const Matrix& U, const Matrix& p, const Matrix& b);
Matrix matrix_invert(const Matrix& m);
Matrix in_place_LUP(Matrix& m);
Matrix random_matrix(int rows, int cols);
Matrix sle_solve(const Matrix& A, const Matrix& b);
Matrix solve_system(const Matrix& M, const Matrix& b);
void test_matrix(void);
