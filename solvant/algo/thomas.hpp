#ifndef THOMASSOLV
#define THOMASSOLV
#include "core/tridiagonal_matrix.hpp"
namespace solvant {
template <typename T, std::size_t N>
void thomas(const std::array<T, N>& rhs,
            const solvant::tridiagonal_matrix<T, N>& m,
            std::array<T, N>& x) {
    // strip the matrix into bands
    std::array<T, N - 1> a, c;
    std::array<T, N> b;
    std::array<T, N> d = rhs;
    b[0] = m(0, 0);
    b[N - 1] = m(N - 1, N - 1);
    a[N - 2] = m(N - 1, N - 2);
    c[0] = m(0, 1);
    for (std::size_t i = 1; i < N - 1; ++i) {
        a[i - 1] = m(i, i - 1);
        b[i] = m(i, i);
        c[i] = m(i, i + 1);
    }

    for (std::size_t i = 1; i < N; ++i) {
        std::size_t im1 = i - 1;
        a[im1] /= b[im1];
        b[i] = b[i] - a[im1] * c[im1];
        d[i] = d[i] - a[im1] * d[im1];
    }

    x[N - 1] = d[N - 1] / b[N - 1];
    for (std::size_t i = N - 1; i != 0;) {
        --i;
        x[i] = (d[i] - c[i] * x[i + 1]) / b[i];
    }
}
}  // namespace solvant
#endif
