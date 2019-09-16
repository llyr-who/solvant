#ifndef SOLV
#define SOLV
#include "base/matrix.hpp"
// Absract base class for solver mechanism. 
// Note that we can "solve" non-square systems (think LS)
namespace solvant {
namespace solver {
template <typename T, std::size_t R, std::size_t C>
class Solver {
public:
    virtual void solve(std::array<T, R>& rhs) = 0;
};
}  // namespace solver
}  // namespace solvant
#endif
