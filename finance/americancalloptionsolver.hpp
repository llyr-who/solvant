#ifndef AMERICALL
#define AMERICALL

#include "solver/tripsor.hpp"

namespace solvant {
namespace finance {
template <typename T>
class AmericanCallOptionSolver {
public:
    AmericanCallOptionSolver();
    void init(float E, float T, float sig, float r, maxIterations,
              solvant::solver::TriPSOR<float, N - 2>* solver);
    void solve();
    void writeSolutionToFile(std::string filename);

private:
    bool m_init;  // has the solver been init'd?

    // Financial variables
    float m_sig;  // Volitility
    float m_r;    // interest rate

    float m_dt;
    float m_dx;

    solvant::solver::TriPSOR<float, N - 2>* p_solver;
    std::array<std::array<float, N - 2>, M> m_sols;
};
}  // namespace finance
}  // namespace solvant
#endif
