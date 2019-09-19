#ifndef TDIRSOLV
#define TDIRSOLV
#include "solver/directsolver.hpp"
#include "base/bmatrix.hpp"
namespace solvant {
namespace solver {
template <typename T, std::size_t N>
class DirectTriSolver : public DirectSolver<T, N> {
protected:
    bool m_init;
    base::BMatrix<T,N,3> m_M;
public:
    DirectTriSolver() : m_init(false) {}
    virtual void init(base::BMatrix<T,N,3>&& M) {
        m_M = std::move(M);
        m_init = true;
    }
    virtual void solve(const std::array<T, N>& rhs, std::array<T, N>& x) = 0;
};
}  // namespace solver
}  // namespace solvant
#endif
