#ifndef BANDMATDEF
#define BANDMATDEF

#include <array>
#include "base/matrix.hpp"
namespace solvant {
namespace base {
template <typename T, std::size_t R, std::size_t B>
class BMatrix : public Matrix<T, R, R> {
private:
    std::array<T, B * R> m_data;

public:
    BMatrix() : Matrix<T, R, R>(){};
    ~BMatrix(){};
};
}  // namespace base
}  // namespace solvant

#endif
