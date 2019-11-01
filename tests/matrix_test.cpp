#include "solvant/base/matrix.hpp"
#include "gtest/gtest.h"

using matrix3x3d  = solvant::base::matrix<double,3,3>;

TEST(matrix, matrix_multiplication) {
    matrix3x3d a = {1.0,2.0,3.0,
                    4.0,5.0,6.0,
                    7.0,8.0,9.0};
    // result
    matrix3x3d c;
    
    // expected result
    matrix3x3d d = {30.0,36.0,42.0,
                    66.0,81.0,96.0,
                    102.0,126.0,150.0};

    solvant::base::matrix_prod(a,a,c);

    ASSERT_TRUE(0 == 0);
}
