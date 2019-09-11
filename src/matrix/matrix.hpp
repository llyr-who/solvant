#ifndef MATRIXDEF
#define MATRIXDEF
#include <cmath>

// File : matrix.h
// Abstract base class for deriving matrices
// that are to be used on non-embedded devices
// i.e your Macbook

namespace SolvAnt {
namespace Matrix {
class Matrix {
private:
    int m_Rows;
    int m_Cols;
public:
    Matrix();
    virtual ~Matrix();
};
}  // namespace Matrix
}  // namespace SolvAnt
#endif
