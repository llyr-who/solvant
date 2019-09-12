#ifndef BANDMATDEF
#define BANDMATDEF

#include <array>
#include "base/matrix.hpp"
namespace solvant {
namespace base {
template <typename T, std::size_t Rows, std::size_t Bands>
class BandedMatrix : public Matrix {
private:
    std::array<T, Bands * Rows> m_data;

public:
    BandedMatrix() : Matrix(){};
    ~BandedMatrix() {};

    virtual void circshift(std::size_t sft_amt, std::size_t dim) {}
};
}  // namespace Base
}  // namespace SolvAnt

#endif
