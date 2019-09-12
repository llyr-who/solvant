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
private:
    std::size_t m_rows = R;
    std::size_t m_cols = C;
public:
    Matrix() {};
    virtual ~Matrix() {} ;
};
}  // namespace Base
}  // namespace SolvAnt
#endif
