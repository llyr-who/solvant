#ifndef MATRIXDEF
#define MATRIXDEF
#include <array>
#include <cmath>
#include <iostream>
#include <memory>
namespace solvant {
namespace base {
template <typename T, std::size_t R, std::size_t C>
class matrix {
private:
    std::array<T, R * C> m_data;

public:
    matrix(){};
    virtual ~matrix(){};

    std::size_t rows() const { return R; }
    std::size_t cols() const { return C; }

    void print() {
        for (std::size_t i = 0; i < R; i++) {
            std::cout << '\n';
            for (std::size_t j = 0; j < C; j++) {
                std::cout << (*this)(i, j) << " ";
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
    }

    virtual T operator()(const std::size_t i, const std::size_t j) const {
        return m_data[i * C + j];
    }

    virtual T& operator()(const std::size_t i, const std::size_t j) {
        return m_data[i * C + j];
    }
    
    T* operator[](const std::size_t row) { return &m_data[row * C]; }
};

template<typename T, std::size_t R, std::size_t K, std::size_t C>
inline void matrix_prod(const matrix<T, R, K>& a,
                        const matrix<T, K, C>& b,
                        matrix<T, R, C>& c) {

}

}  // namespace base
}  // namespace solvant
#endif
