#ifndef MATRIXDEF
#define MATRIXDEF
#include <array>
#include <cmath>
#include <iostream>
#include <memory>
namespace solvant {
namespace base {
/**
 * Matrix class
 */
template <typename T, std::size_t R, std::size_t C>
class matrix {
private:
    std::array<T, R * C> m_data;

public:
    matrix(){};
    matrix(std::array<T,R*C> a) {
        m_data = std::move(a);
    }
    matrix operator=(std::array<T,R*C>a) {
        m_data = std::move(a);
    }
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
    
    //! obtain raw row data
    T* operator[](const std::size_t row) { return &m_data[row * C]; }
    //! obtain raw row data
    const T* operator[](const std::size_t row) const {
        return &m_data[row * C];
    }
};

/** Calculates the product between two matrices.
 *
 */
template <typename T, std::size_t R, std::size_t K, std::size_t C>
inline void matrix_prod(const matrix<T, R, K>& a, const matrix<T, K, C>& b,
                        matrix<T, R, C>& c) {
    for (std::size_t i = 0; i < R; i++) {
        const auto ai = a[i];  // obtain row i of a
        auto ci = c[i];        // obtain row i of c
        for (std::size_t j = 0; j < C; j++) {
            T r = 0;
            for (size_t k = 0; k < K; k++) {
                r += ai[k] * b[k][j];
            }
            ci[j] = r;
        }
    }
}

}  // namespace base
}  // namespace solvant
#endif
