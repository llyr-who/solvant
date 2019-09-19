#ifndef AMERICALL
#define AMERICALL

namespace solvant {
namespace finance {
template <typename T>
class AmericanCallOptionSolver {
public:
    EuroCallOptionSolver();
    void init(float E, float T, float sig, float r,
              solvant::solver::IterativeTriSolver<float, N - 2>* solver);
    void solve();
    void writeSolutionToFile(std::string filename);

private:
    bool m_init;  // has the solver been init'd?

    // Financial variables
    float m_E;    // Exercise price
    float m_T;    // Expiry date
    float m_sig;  // Volitility
    float m_r;    // interest rate

    // non-dimensional parameters
    float m_k;

    float m_dt;
    float m_dx;
    float m_alpha;


    solvant::solver::IterativeTriSolver<float, N - 2>* p_solver;
    // pImpl -< can use differnt direct trisolver
    std::array<std::array<float, N - 2>, M> m_sols;
};
}  // namespace finance
}  // namespace solvant
#endif
