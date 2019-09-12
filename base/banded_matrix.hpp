#ifndef BANDMATDEF
#define BANDMATDEF

#include <array>
#include "base/matrix.hpp"
namespace solvant {
namespace base {
template <typename T, std::size_t R, std::size_t B>
class BandedMatrix : public Matrix<T, R, R> {
private:
    std::array<T, B * R> m_data;
public:
    BandedMatrix() : Matrix<T,R,R> (){};
    ~BandedMatrix(){};

    virtual void circshift(std::size_t sft_amt, std::size_t dim) {}
};
}  // namespace base
}  // namespace solvant

#endif
