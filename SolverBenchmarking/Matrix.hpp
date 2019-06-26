#ifndef MATRIXDEF
#define MATRIXDEF

#include<cmath>

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
    Matrix Mult(const Matrix& A, const Matrix& B); // A*B
    Matrix Mult(const double &a, const Matrix &A); // a*A
    Matrix Add(const Matrix& A, const Matrix& B); // A+B
    
    //  solve for x ; Ax=b ------------------------------------------
    Matrix SolveLUPartialPivoting(const Matrix& b);
    //  ...
    //  -------------------------------------------------------------
    
    //  solve for inverse -------------------------------------------
    //  All this function does is obtain solutions when the rhs are
    //  cannonical basis vectors and compounds them into the inverse.
    Matrix obtainInverse();
    //  -------------------------------------------------------------
    
    
    Matrix& operator=(const Matrix& M);
    
    double& operator()(int i,int j) const;
    void interchangeRows(int i,int j,int I,int J);
    Matrix transpose();
    void setMatrix(Matrix A);
    void print();
};
#endif
