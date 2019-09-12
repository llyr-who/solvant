#ifndef MATRIXDEF
#define MATRIXDEF

#include "include/matrix.hpp"
namespace SolvAnt {
namespace Base {
template <typename T, std::size_t Rows, std::size_t Bands>
class BandedMatrix : public Matrix<T, Rows, Rows> {
private:
    std::array<T, Bands*Rows> m_data;
public:
    BandedMatrix() : Matrix(){};
    ~BandedMatrix() {}
}
}  // namespace Base
}  // namespace SolvAnt

#endif
