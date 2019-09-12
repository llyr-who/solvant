#ifndef BANDMATDEF
#define BANDMATDEF
// class for banded matrix
// B = number of bands
// B = 0 : Diagonal
// B = 1 : Tridiagonal
// ...
#include <array>
#include "base/matrix.hpp"
namespace solvant {
namespace base {
template <typename T, std::size_t R, std::size_t B>
class BMatrix : public Matrix<T, R, R> {
protected:
    std::array<T, R*(2 * B + 1)> m_data;

public:
    BMatrix() : Matrix<T, R, R>(){};
    BMatrix(std::array<T, R>&& diagonal_constants) : Matrix<T, R, R>() { 
    }
    virtual ~BMatrix(){};
};
}  // namespace base
}  // namespace solvant

#endif
