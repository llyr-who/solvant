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
class Matrix {
private:
public:
    Matrix() {};
    virtual ~Matrix() {} ;

    virtual void circshift(std::size_t sft_amt, std::size_t dim) = 0;
};
}  // namespace Base
}  // namespace SolvAnt
#endif
