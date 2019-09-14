#include <iostream>
#include "base/bmatrix.hpp"

int main(int argc, const char * argv[]) {
    // Diagonal matrix
    std::cout << "creating tri-diag matrix" << std::endl;
    solvant::base::BMatrix<double, 5,1> t({1,2,3});  

    t.print(); 

    return 0;
}
