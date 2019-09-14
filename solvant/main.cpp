#include <iostream>
#include "base/bmatrix.hpp"

int main(int argc, const char * argv[]) {
    // Mass Matrix :)
    solvant::base::BMatrix<double,20,3> mass({-1,2,-1});  

    mass.print(); 

    return 0;
}
