#ifndef MATRIXDEF
#define MATRIXDEF
#include <cmath>
#include <iostream>
// File : matrix.h
// Abstract base class for deriving matrices
// that are to be used on non-embedded devices
// i.e your Macbook

namespace SolvAnt {
namespace Base {
template<typename T, std::size_t Rows, std::size_t Columns>
class Matrix {
private:
public:
    Matrix();
    virtual ~Matrix();
};
}  // namespace Matrix
}  // namespace SolvAnt
#endif
