#ifndef TDIRSOLV
#define TDIRSOLV
// The ethos behind this code is that when we are
// ins a situation where we are solving tridagonal
// systems directly, the matrix is static and we
// are solving many vectors against this system.
//
// Therefore we initialise the system with matrix
// data then fire off solve commands which solve
// the system with this
//
#include "solver/directsolver.hpp"
#include "base/bmatrix.hpp"
namespace solvant {
namespace solver {
template <typename T, std::size_t N>
class DirectTriSolver : public DirectSolver<T, N> {
    bool m_init;
    const std::array<T, 3 * N>& m_M;  // just store a reference?
    std::array<T, N - 1> m_c;
    std::array<T, N> m_d;

public:
    virtual void init(const base::BMatrix<T,N,3>& M) {
        m_M = M.data();
        m_init = true;
    }
    // look into cache locality
    virtual void solve(const std::array<T, N>& rhs, std::array<T, N>& x) {
        m_c[0] = m_M[2 * N] / m_M[N];
        m_d[0] = rhs[0] / m_M[N];
        for (std::size_t i = 1; i < N - 1; i++) {
            T denom = m_M[N + i] - m_M[i + 1] * m_c[i - 1];
            m_c[i] = m_M[2 * N + i] / denom;
            m_d[i] = (rhs[i] - m_M[i + 1] * m_d[i - 1]) / denom;
        }

        x[N - 1] = m_d[N - 1];
        for (std::size_t i = N - 2; i > -1; i--) {
            x[i] = m_d[i] - m_c[i] * x[i + 1];
        }
    }
};
}  // namespace solver
}  // namespace solvant
#endif
