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
    const T* m_matrixData;
    bool m_init;

public:
    DirectTriSolver(const base::BMatrix<T, N, 3>& M) {
        if (M.rows() == M.cols()) {
            m_matrixData = M.getData();
        }
    };
    virtual void solve(std::array<T, N>& rhs){
        // .. Thomas
    };
};
}  // namespace solver
}  // namespace solvant
#endif
