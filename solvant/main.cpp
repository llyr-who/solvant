#include <iostream>
#include "base/banded_matrix.hpp"
#include "base/dense_matrix.hpp"
#include "base/tri_matrix.hpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    solvant::base::BMatrix<double,10,2> r; 
    solvant::base::DMatrix<double,10,2> d;
    solvant::base::TriMatrix<double, 10> t({1,2,3});
    
    t.print();

    return 0;
}
