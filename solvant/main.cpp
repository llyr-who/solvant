#include <iostream>
#include "solver/finsolv/eurocalloptionsolver.hpp"
#include "solver/thomas.hpp"
int main(int argc, const char* argv[]) {
    // Euro solver
    solvant::solver::finsolv::EuroCallOptionSolver<10, 10> ecos;
    // pik our weapon of choice 
    solvant::solver::Thomas<float, 8> dts;
    ecos.init(100, 10, 0.01, 0.1, &dts);
    ecos.solve();
    ecos.writeSolutionToFile("asd");
}
