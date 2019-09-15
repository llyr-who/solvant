#include <iostream>
#include "base/bmatrix.hpp"
#include "solver/tsolver.hpp"

int main(int argc, const char * argv[]) {
    // Mass Matrix :)
    solvant::base::BMatrix<double,20,3> mass({-1,2,-1});  

    mass.print(); 

    solvant::solver::TSolver<double, 20, 20> slv(mass);
    slv.solve();
    return 0;
}
