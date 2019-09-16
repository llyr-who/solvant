#ifndef DIRSOLV
#define DIRSOLV
#include "solver/solver.hpp"
namespace solvant {
namespace solver {
template <typename T, std::size_t N>
class DirectSolver : public Solver<T, N, N> {
    virtual void solve(std::array<T, N>& rhs) {
        std::cout << "solving D" << std::endl;
    }
};
}  // namespace solver
}  // namespace solvant
#endif
