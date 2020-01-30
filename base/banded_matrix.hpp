#ifndef BANDMATDEF
#define BANDMATDEF
//! This class defines a SYMETRIC banded matrix. So we are only interested
//! in banded matrices that have equal upper and lower bandwidth. That is,
//! the value of B is equal to the upper bandwidth plus the lower bandwidth
//! plus 1. e.g for a tridiagonal matrix B = 3.
//! We don't find any use for having seperate upper and lower band matrices.
//!
//! Banded matrices are stored in row major order. For example the matrix
//! [1 2 0 0 0 0]
//! [2 1 2 0 0 0]
//! [0 2 1 2 0 0]
//! [0 0 2 1 2 0]
//! [0 0 0 2 1 2]
//! [0 0 0 0 2 1]
//! = [x 1 2 2 1 2 2 1 2 ... 2 1 2 2 1 x]
#include <array>
namespace solvant {
namespace base {

template <std::size_t B>
constexpr bool out_of_bounds(const std::size_t& i, const std::size_t& j) {
    return i < j ? j - i < (B >> 1) : i - j < (B >> 1);
}

template <typename T, std::size_t N, std::size_t B>
class banded_matrix {
private:
    std::array<T, N * B> m_data;

public:
    banded_matrix() : m_data({}){};
    banded_matrix(std::array<T, B>&& diagonal_constants);
    virtual ~banded_matrix(){};

    // move assignment operator
    banded_matrix& operator=(banded_matrix&& other) noexcept {
        if (this != &other) {
            m_data = std::move(other.m_data);
        }
        return *this;
    }

    const T* data() const { return m_data.data(); }

    std::size_t bands() const { return B; }

    T at(const std::size_t i, const std::size_t j) {
        if (i >= N || j >= N || i < 0 || j < 0) {
            throw std::out_of_range("index out of bounds");
        }
        if (out_of_bounds<B>(i, j)) {
            return 0;
        }
        return (*this)(i, j);
    }
    void set(const std::size_t i, const std::size_t j, const T val) {
        if (i >= N || j >= N || i < 0 || j < 0) {
            throw std::out_of_range("index out of bounds");
        }
        if (out_of_bounds<B>(i, j)) {
            (*this)(i, j) = val;
        }
    }

    //! using "row"-major (see above) form
    T operator()(const std::size_t i) const { return m_data[i]; }

    //! standard (i,j) access
    T operator()(const std::size_t i, const std::size_t j) const {
        return out_of_bounds<B>(i, j) ? m_data[i * B + (B >> 1) + (i - j)] : 0;
    }

    T& operator()(const std::size_t i, const std::size_t j) {
        return m_data[i * B + (B >> 1) + (i - j)];
    }

    //! obtain raw row data
    T* operator[](const std::size_t row) { return &m_data[row * B]; }
};  // namespace base

template <typename T, std::size_t N, std::size_t B>
banded_matrix<T, N, B>::banded_matrix(std::array<T, B>&& diagonal_constants) {
    for (std::size_t j = 0; j < N; ++j) {
        for (std::size_t i = 0; i < B; ++i) {
            m_data[j * B + i] = diagonal_constants[i];
        }
    }
}

//! The theoretical optimal is the band of the output matrix
//! multiplied by N. approximately. There are slightly more
//! complicated algorithms that acheive this by storing
//! the banded matrix a little differently to how I have.
//! maybe this will be part of a blog post in future.
template <typename T, std::size_t N, std::size_t B1, std::size_t B2>
void matrix_prod(const banded_matrix<T, N, B1>& A,
                 const banded_matrix<T, N, B2>& B,
                 banded_matrix<T, N, 2 * ((B1 >> 1) + (B2 >> 1)) + 1>& C) {
    // obtain floor(B/2);
    std::size_t C_band_div_2 = (2 * ((B1 >> 1) + (B2 >> 1)) + 1) >> 1;
    for (std::size_t i = 0; i < N; ++i) {
        // obtain bounds for updating C
        std::size_t b_begin = i > C_band_div_2 ? i - C_band_div_2 : 0;
        std::size_t b_end = i > N - 1 - C_band_div_2 ? N : i + C_band_div_2;
        for (std::size_t k = b_begin; k < b_end; ++k) {
            const auto aik = A(i, k);
            for (std::size_t j = b_begin; j < b_end; ++j) {
                C(i, j) += aik * B(k, j);
            }
        }
    }
}
}  // namespace base
}  // namespace solvant
#endif
