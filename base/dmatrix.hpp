#ifndef DENSEMATDEF
#define DENSEMATDEF

#include <vector>
#include "base/matrix.hpp"
namespace solvant {
namespace base {
template <typename T, std::size_t R, std::size_t C>
class DMatrix : public Matrix<T, R, C> {
protected:
    std::vector<std::vector<T>> m_data;

public:
    DMatrix() : Matrix<T, R, C>(){};
    ~DMatrix(){};
    // sft : how many shifts
    // dim : the dimension
    virtual void circshift(std::size_t sft, bool dim = true) {
        
    };
};
}  // namespace base
}  // namespace solvant

#endif
