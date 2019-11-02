#include <iostream>
#include "solvant/base/matrix.hpp"
#include "solvant/utils/timer.hpp"
int main(int argc, const char* argv[]) {
    solvant::utils::timer t;
    solvant::base::matrix<double, 1000, 1000> A;
    solvant::base::matrix<double, 1000, 1000> B;
    solvant::base::matrix<double, 1000, 1000> C;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            A(i, j) = 0.1*i;
            B(i, j) = 0.1*j;
        }
    }
    auto begin = t.elapsed();
    solvant::base::matrix_prod(A, B, C);
    auto end = t.elapsed();
    std::cout << end - begin << std::endl;

}
