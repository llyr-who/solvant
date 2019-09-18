#include <iostream>
#include "base/bmatrix.hpp"
#include "solver/directtrisolver.hpp"

int main(int argc, const char * argv[]) {
    // Mass Matrix :)
    solvant::base::BMatrix<double,20,3> mass({-1,2,-1});  
    // RHS (and solution)
    std::array<double, 20> rhs, x;
    for(std::size_t i = 0 ;i < 20; i++) {
        rhs[i] = 1;
    }

    // Define solver
    solvant::solver::DirectTriSolver<double, 20> slv(mass);
    // Solve a few times
    for(std::size_t i = 0 ; i < 1000; i++) {
        slv.solve(rhs, x);
    }
    return 0;
}
