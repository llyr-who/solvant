#ifndef SOLV
#define SOLV
#include "base/matrix.hpp"
#include <array>
// Absract base class for solver mechanism. 
// Note that we can "solve" non-square systems (think LS)
namespace solvant {
namespace solver {
template <typename T, std::size_t R, std::size_t C>
class Solver {
public:
    virtual void solve(const std::array<T, R>& rhs, std::array<T, R>& x) = 0;
    virtual ~Solver() {}
};
}  // namespace solver
}  // namespace solvant
#endif
