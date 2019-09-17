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
// REMEMBER to implement destructor here
#include "solver/directsolver.hpp"
namespace solvant {
namespace solver {
template <typename T, std::size_t N>
class DirectTriSolver : public DirectSolver<T, N> {
    const T* m_M;
    const std::array<T, N - 1> m_c;
    const std::array<T, N> m_d;

public:
    DirectTriSolver(const base::BMatrix<T, N, 3>& M) : m_M{M.getData()} {}

    ~DirectTriSolver() {}

    virtual void solve(std::array<T, N>& rhs) {
        m_c[0] = m_M[2 * N] / m_M[N];
        m_d[0] = rhs[0] / m_M[N];
        for (int i = 1; i < N - 1; i++) {
            T denom = m_M[N + i] - m_M[i + 1] * m_c[i - 1];
            m_c[i] = m_M[2 * N + i] / denom;
            m_d[i] = 
        }
    }
};
}  // namespace solver
}  // namespace solvant
#endif
