#include <iostream>
#include "solver/finsolv/eurocalloptionsolver.hpp"

int main(int argc, const char * argv[]) {
   solvant::solver::finsolv::EuroCallOptionSolver<10, 10> ecos;
   ecos((1.0,1.0,1.0,1.0); 
   solvant::solver::DirectTriSolver<float, 8> dts;
   ecos.init(&dts);
}
