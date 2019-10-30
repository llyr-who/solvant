#ifndef THOMASSOLV
#define THOMASSOLV
#include "base/tridiagonal_matrix.hpp"
namespace solvant {
namespace solver {
template <typename T, std::size_t N>
class thomas {
	virtual ~thomas() {};
    virtual void solve(const std::array<T, N>& rhs,
    				   const solvant::base::tridiagonal_matrix<T,N>& m,
                       std::array<T, N>& x) {
        std::array<T, N - 1> c;
        std::array<T, N> d;
        c[0] = m[2 * N] / m[N];
        d[0] = rhs[0] / m[N];
        for (std::size_t i = 1; i < N - 1; i++) {
            T denom = m[N + i] - m[i + 1] * c[i - 1];
            c[i] = m[2 * N + i] / denom;
            d[i] = (rhs[i] - m[i + 1] * d[i - 1]) / denom;
        }

        x[N - 1] = d[N - 1];
        for (std::size_t i = N - 2; i > -1; i--) {
            x[i] = d[i] - c[i] * x[i + 1];
        }
    }
};
}  // namespace solver
}  // namespace solvant
#endif
