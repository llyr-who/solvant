#ifndef MATRIXDEF
#define MATRIXDEF
#include <cmath>
#include <iostream>
// File : matrix.h
// Abstract base class for deriving matrices
// that are to be used on non-embedded devices
// i.e your Macbook

namespace solvant {
namespace base {
template <typename T, std::size_t R, std::size_t C>
class Matrix {
public:
    Matrix() {};
    virtual ~Matrix() {} ;
    //virtual solve() = 0;
};
}  // namespace Base
}  // namespace SolvAnt
#endif
