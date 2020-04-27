#include "solvant/core/matrix.hpp"

int main() {
    using matrix3x3 = solvant::matrix<double, 2, 2>;

    matrix3x3 A = {1.0, 2.0, 3.0, 4.0};
    matrix3x3 B = {1.0, 2.0, 3.0, 4.0};
    matrix3x3 C;  // answer;

    solvant::matrix_prod(A, B, C);

    solvant::print(C);
}
