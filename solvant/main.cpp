#include <iostream>
#include "base/bmatrix.hpp"
#include "solver/directtrisolver.hpp"

int main(int argc, const char * argv[]) {
    // Mass Matrix :)
    solvant::base::BMatrix<double,20,3> mass({-1,2,3});  
    // RHS
    std::array<double, 20> rhs;
    mass.print(); 

    solvant::solver::DirectTriSolver<double, 20> slv(mass);
    slv.solve(rhs);
    return 0;
}
