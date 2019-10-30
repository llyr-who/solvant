#include "solvant/base/matrix.hpp"
#include "gtest/gtest.h"

using matrix3x3f = solvant::base::matrix<float,3,3>;

TEST(matrix, matrix_multiplication) {
    matrix3x3f a = {1.0,0.2,3.0,
                    4.0,5.0,0.6,
                    0.7,0.8,0.9};
    matrix3x3f b = {1.0,2.2,3.4,
                    4.1,5.5,6.4,
                    7.3,8.4,9.7};
    
    ASSERT_TRUE(0 == 0);
}
