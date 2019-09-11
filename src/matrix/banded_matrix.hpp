#ifndef MATRIXDEF
#define MATRIXDEF

#include "matrix.hpp"
namespace SolvAnt {
namespace Matrix {
template<typename T>
class BandedMatrix : public Matrix {
private:
    T** m_data;
public:
    BandedMatrix() : Matrix() {};
    ~BandedMatrix() {}
}
}  // namespace Matrix
}  // namespace SolvAnt

#endif
