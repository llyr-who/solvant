#ifndef EUROCALL
#define EUROCALL
// there is no point using a non-direct solver
#include "solver/directtrisolver.hpp"

#include <algorithm>
#include <array>
namespace solvant {
namespace solver {
namespace finsolv {
template <std::size_t N, std::size_t M>
class EuroCallOptionSolver {
public:
    EuroCallOptionSolver();
    void init(float E, float T, float sig, float r,
              solvant::solver::DirectTriSolver<float, N - 2>* solver);
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

    solvant::solver::DirectTriSolver<float, N - 2>* p_solver;
    // pImpl -< can use differnt direct trisolver
    std::array<std::array<float, N - 2>, M> m_sols;
};
}  // namespace finsolv
}  // namespace solver
}  // namespace solvant

template <std::size_t N, std::size_t M>
solvant::solver::finsolv::EuroCallOptionSolver<N, M>::EuroCallOptionSolver()
    : m_init(false) {}

template <std::size_t N, std::size_t M>
void solvant::solver::finsolv::EuroCallOptionSolver<N, M>::init(
    float E, float T, float sig, float r,
    solvant::solver::DirectTriSolver<float, N - 2>* solver) {
    m_E = E;
    m_T = T;
    m_sig = sig;
    m_r = r;
    p_solver = solver;
    // set non-dim params
    m_k = 2 * m_r / (m_sig * m_sig);

    // initial condition
    std::transform(
        m_sols[0].begin(), m_sols[0].end(), m_sols[0].begin(), [this](float x) {
            return std::max(
                std::exp(0.5 * (m_k + 1) * x) - std::exp(0.5 * (m_k - 1) * x),
                0.0);
        });

    m_dt = 1.0 / M;
    m_dx = 1.0 / N;
    m_alpha = m_dt / (m_dx * m_dx);

    base::BMatrix<float, N - 2, 3> A({static_cast<float>(-0.5 * m_alpha),
                                      static_cast<float>(1 + m_alpha),
                                      static_cast<float>(-0.5 * m_alpha)});
    p_solver->init(std::move(A));
    m_init = true;
}

template <std::size_t N, std::size_t M>
void solvant::solver::finsolv::EuroCallOptionSolver<N, M>::solve() {
    if (!m_init) return;
    std::array<float, N - 2> rhs;
    std::cout << std::endl;
    for (int i = 0; i < M - 1; i++) {
        std::transform(rhs.begin(), rhs.end(), rhs.begin(),
                       [this, &i, j = 0](float x) mutable {
                           return (1 - m_alpha) * m_sols[i][j] +
                                  0.5 * m_alpha *
                                      (m_sols[i][j - 1] + m_sols[i][j + 1]);
                           j++;
                       });

        rhs[0] += 0.5 * m_alpha;
        rhs[N - 2] += 0.5 * m_alpha;
        for(auto& e : rhs){
            std::cout << e << std::endl;
        }
        p_solver->solve(rhs, m_sols[i + 1]);
    }
}

template <std::size_t N, std::size_t M>
void solvant::solver::finsolv::EuroCallOptionSolver<N, M>::writeSolutionToFile(
    std::string filename) {
    for(auto& sol : m_sols) {
        std::cout << std::endl;
        for(auto& e : sol) {
            std::cout << e << " ";
        }
    }

}

#endif
