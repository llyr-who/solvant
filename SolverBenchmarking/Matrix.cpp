#include<iostream>
#include "Vector.hpp"
#include"Matrix.hpp"

Matrix::Matrix(int rows, int cols)
{
    mRows = rows;
    mCols = cols;
    mData = new double[rows*cols];
    for(int i=0; i <mRows;i++)
    {
        for(int j=0;j<mCols;j++)
        {
            mData[j*mRows+i] = 0;
        }
    }
}

Matrix::Matrix(const Matrix&m1)
{
    mRows = m1.mRows;
    mCols = m1.mCols;
    mData = new double[mRows*mCols];
    for(int i = 0; i<mRows;i++)
    {
        for(int j = 0; j<mCols;j++)
        {
            mData[j*mRows+i] = m1(i,j);
        }
    }
}

Matrix::~Matrix()
{
    delete[] mData;
}

Matrix operator*( const Matrix &A,const Matrix &B)
{
    if(A.mCols != B.mRows)
    {
        throw Exception("index mismatch","the number of collums in the first matrix needs to equal the number of rows in the second");
    }
    Matrix result(A.mRows,B.mCols);
    for(int i = 0; i<A.mRows;i++)
    {
        
        for (int j = 0; j<B.mCols;j++)
        {
            double entry = 0;
            for(int k = 0; k < A.mCols;k++)
            {
                entry += A(i,k)*B(k,j);
            }
            result(i,j) = entry;
        }
        
    }
    return result;
}

Vector operator*( const Matrix &A,const Vector &b)
{
    Vector result(A.mRows);
    for(int i = 0; i<A.mRows;i++)
    {
        double entry = 0;
        for (int j = 0; j<A.mCols;j++)
        {
            entry += A(i,j)*b(j);
        }
        result(i) = entry;
    }
    return result;
}

Matrix operator*( const double &a,const Matrix &A)
{
    Matrix result(A.mRows,A.mCols);
    for(int i = 0; i<A.mRows;i++)
    {
        for (int j = 0; j<A.mCols;j++)
        {
            result(i,j) = A(i,j)*a;
        }
    }
    return result;
}

Matrix operator+(const Matrix& A, const Matrix& B)
{
    //need to check size.
    Matrix result(A.mRows,A.mCols);
    for(int i = 0; i<A.mRows;i++)
    {
        for (int j = 0; j<A.mCols;j++)
        {
            result(i,j) = A(i,j) + B(i,j);
        }
    }
    return result;
}

Vector operator/(const Vector &b, const Matrix &A)
{
    //Call Guassian Elimination (return LU)
    if(A.mCols != A.mRows)
    {
        throw Exception("index mismatch","non-square matrix");
    }
    //This will solve the matrix using guasian ellimination with partial pivoting
    int m = A.mCols;
    Matrix U=A,L = eye(m),P=eye(m);
    for(int k =0; k < m-1;k++)
    {
        //select i to max u{ik}
        int i = 0;
        double max = 0;
        for(int l = 0; l < m;l++)
        {
            if(U(l,k) > max){i=l;max = U(l,k);}
        }
        U.interchangeRows(i,k,k,m);
        L.interchangeRows(k,i,0,k-1);
        P.interchangeRows(i,k,0,m);
        for(int j =k+1; j < m;j++)
        {
            L(j,k) = U(j,k)/U(k,k);
            for(int s = k; s<m;s++)
            {
                U(j,s) = U(j,s) - L(j,k)*U(k,s);
            }
        }
    }
    
    Vector bb = P*b;
    Vector y(m),x(m);
    
    //Call forward substitution (returns vector) to solve "Ly=bb"
    y(0) = bb(0)/L(0,0);
    for(int j = 1;j<m;j++)
    {
        double SUM = 0;
        for(int k = 0;k<j;k++)
        {
            SUM += y(k)*L(j,k);
        }
        y(j) = (bb(j)-SUM)/L(j,j);
    }
    
    // Call backward substitution Ux = y
    x(m-1) = y(m-1)/U(m-1,m-1);
    for(int j = m-1;j > -1;j--)
    {
        double SUM = 0;
        for(int k = j+1;k<m;k++)
        {
            SUM += x(k)*U(j,k);
        }
        x(j) = (y(j)-SUM)/U(j,j);
    }
    return x;
}


std::ostream& operator<<(std::ostream& os, const Matrix& M)
{
    
    for(int i = 0; i < M.mRows; i++)
    {
        for(int j =0; j < M.mCols;j++)
        {
            os << M(i,j) << " ";
        }
        os << std::endl;
    }
    return os;
}

Matrix& Matrix::operator=(const Matrix& M)
{
    for(int i = 0; i < mRows;i++)
    {
        for(int j = 0;j<mCols;j++)
        {
            mData[j*mRows + i] = M(i,j);
        }
    }
    
    return *this;
}

double& Matrix::operator()(int i, int j) const
{
    return mData[i+j*mRows];
}

void Matrix::interchangeRows(int i,int j,int I, int J)
{
    double temp[mCols];
    for(int k =I; k< J;k++)
    {
        temp[k]= mData[k*mRows + i];
        mData[k*mRows + i] = mData[k*mRows + j];
        mData[k*mRows+j] = temp[k];
    }
    
}

Matrix Matrix::transpose()
{
    Matrix At(mCols,mRows);
    for(int i =0;i<mRows;i++)
    {
        for(int j=0;j<mCols;j++)
        {
            At.mData[i*mCols +j] = mData[j*mRows+i];
        }
    }
    return At;
}

void Matrix::print()
{
    for(int i =0;i<mRows;i++)
    {
        for(int j=0;j<mCols;j++)
        {
            std::cout << mData[j*mRows + i] << " ";
        }
        std::cout << std::endl;
    }
}

Vector Matrix::size()
{
    Vector sz(2);
    sz(0)=mRows;
    sz(1)=mCols;
    return sz;
}

void Matrix::setMatrix(Matrix A)
{
    mCols = A.mCols;
    mRows = A.mRows;
    mData = new double[mCols*mRows];
    
    for(int i =0;i<mRows;i++)
    {
        for(int j=0;j<mCols;j++)
        {
            mData[j*mRows+i]=A.mData[j*mRows+i];
        }
    }
}

Matrix eye(int n)
{
    Matrix a(n,n);
    for(int i = 0;i<n;i++)
    {
        a(i,i)=1.0;
    }
    return a;
}

Matrix ones(int n)
{
    Matrix a(n,n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a(i,j) = 1.0;
    return a;
}
