#ifndef TRIMATDEF
#define TRIMATDEF
#include "base/banded_matrix.hpp"
namespace solvant {
namespace base {
template <typename T, std::size_t R>
class TriMatrix : public BMatrix<T, R, 3> {
protected:
    using BMatrix<T, R, 3>::m_data;
public:
    TriMatrix() : BMatrix<T, R, 3>(){};
    TriMatrix(std::array<T, 3>&& diagonal_constants) : BMatrix<T, R, 3>() {
        for(std::size_t i = 0; i < R; i++) {
            m_data[i + 0*R] = diagonal_constants[0];
            m_data[i + 1*R] = diagonal_constants[1];
            m_data[i + 2*R] = diagonal_constants[2]; 
        }
    }
    ~TriMatrix(){};

    void print() {
        for(int i = 0; i < R; i++) {
            std::cout << m_data[i + 0*R] << " " 
                <<  m_data[i + 1*R] << " " 
                <<  m_data[i + 2*R] << std::endl;
        }
    }
};
}  // namespace base
}  // namespace solvant

#endif
