#ifndef THOMASSOLV
#define THOMASSOLV
#include "solver/solver.hpp"
#include "base/bmatrix.hpp"
namespace solvant {
namespace solver {
template <typename T, std::size_t N>
class Thomas : public Solver<T, N, N> {
private:
    using DirectTriSolver<T, N>::m_init;
    using DirectTriSolver<T, N>::m_M;
    std::array<T, N - 1> m_c;
    std::array<T, N> m_d;
public:
    Thomas() : Solver<T,N>(){}
    // look into cache locality
    virtual void solve(const std::array<T, N>& rhs, std::array<T, N>& x) {
        if(!m_init) return;
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
