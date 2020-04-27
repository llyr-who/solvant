#include "core/matrix.hpp"
#include "gtest/gtest.h"

using matrix3x3d = solvant::matrix<double, 3, 3>;

TEST(matrix, matrix_square) {
    matrix3x3d a = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    // result
    matrix3x3d c;

    // expected result
    matrix3x3d d = {30.0, 36.0, 42.0, 66.0, 81.0, 96.0, 102.0, 126.0, 150.0};

    solvant::matrix_prod(a, a, c);

    ASSERT_TRUE(d == c);
}

TEST(matrix, matrix_multiplication1) {
    matrix3x3d a = {2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 2.0};

    matrix3x3d b = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    // result
    matrix3x3d c;

    // expected result
    matrix3x3d d = {2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0};

    solvant::matrix_prod(a, b, c);

    ASSERT_TRUE(d == c);
}
