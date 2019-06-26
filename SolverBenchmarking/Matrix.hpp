#ifndef MATRIXDEF
#define MATRIXDEF

#include<cmath>

// Make this more self contained.
// That is, a vector is treated as a
// collumn matrix


class Matrix
{
private:
    double *mData;
    int mRows;
    int mCols;
public:
    Matrix(){}
    Matrix(const Matrix& m1);
    Matrix(int rows,int cols);
    ~Matrix();
    
    friend Matrix operator*(const Matrix &A, const Matrix &B);
    friend Vector operator*(const Matrix &A,const Vector &b);
    friend Matrix operator*(const double &a, const Matrix &A);
    friend Matrix operator+(const Matrix& A, const Matrix& B);
    friend Vector operator/(const Vector &b, const Matrix &A);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& M);
    Matrix& operator=(const Matrix& M);
    
    double& operator()(int i,int j) const;
    void interchangeRows(int i,int j,int I,int J);
    Matrix transpose();
    void setMatrix(Matrix A);
    Vector size();
    friend Matrix eye(int n);
    void print();
    
};

//overloads the output operator
Matrix operator*(const Matrix &A, const Matrix &B);
Vector operator*(const Matrix &A,const Vector &b);
Matrix operator*(const double &a, const Matrix &A);
Matrix operator+(const Matrix&A);
Vector operator/(const Vector &b, const Matrix &A);
Matrix eye(int n);
Matrix ones(int n);
#endif
