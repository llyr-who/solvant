#include "solver/solver.hpp"
namespace solvant {
namespace solver {
template <typename T, std::size_t R, std::size_t C>
class TSolver : public Solver<T, R, C> {
public:
    TSolver(const base::Matrix<T, R, C>& M){};
    void solve(){};
};
}  // namespace solver
}  // namespace solvant
