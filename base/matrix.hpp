#ifndef MATRIXDEF
#define MATRIXDEF
#include <array>
#include <cmath>
#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>
namespace solvant {
namespace base {

template <typename T, typename... Ts>
using all_same_type = std::conjunction<std::is_same<T, Ts>...>;

/**
 * Matrix class
 */
template <typename T, std::size_t R, std::size_t C>
class matrix {
private:
    std::array<T, R * C> m_data;

public:
    constexpr matrix(){};

    //! matrix a = {1,2,3,...}
    template <typename... Ts>
    constexpr matrix(Ts&&... elements) noexcept {
        static_assert(all_same_type<T, Ts...>::value, "Types do not match");
        static_assert(sizeof...(Ts) == R * C, "Size of array does not match");
        m_data = std::array<T, R * C>{std::forward<Ts>(elements)...};
    }

    ~matrix(){};

    std::size_t rows() const { return R; }
    std::size_t cols() const { return C; }

    // move outside class, make inline
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

    T operator()(const std::size_t i, const std::size_t j) const {
        return m_data[i * C + j];
    }

    T& operator()(const std::size_t i, const std::size_t j) {
        return m_data[i * C + j];
    }

    //! obtain raw row data
    T* operator[](const std::size_t row) { return &m_data[row * C]; }
    //! obtain raw row data
    const T* operator[](const std::size_t row) const {
        return &m_data[row * C];
    }

    const bool operator==(const matrix<T, R, C>& m) {
        return m_data == m.m_data;
    }
};

/** Calculates the product between two matrices.
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
