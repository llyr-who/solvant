#include <iostream>
#include "base/matrix.hpp"
#include "utils/timer.hpp"
int main(int argc, const char* argv[]) {
    solvant::utils::timer t;
	solvant::base::matrix<double, 800,800> A;
	solvant::base::matrix<double, 800,800> B;
    solvant::base::matrix<double, 800,800> C;
    for(int i = 0; i < 800; i++) {
        for(int j = 0; j < 800; j++) {
            A(i,j) = i;
            B(i,j) = j;
        }
    }
    auto begin = t.elapsed();
    solvant::base::matrix_prod(A,B,C);
    auto end = t.elapsed();
    std::cout << end - begin << std::endl;
}
