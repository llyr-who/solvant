#include "solvant/base/banded_matrix.hpp"
#include "gtest/gtest.h"

using triband_5x5  = solvant::base::banded_matrix<double, 5, 3>;

TEST(tridiagonal, diagonal_constant_init) {
    triband_5x5 a({1,2,3});
    ASSERT_EQ(a(0,0),2);
    ASSERT_EQ(a(0,1),1);
    ASSERT_EQ(a(1,0),3);
    ASSERT_EQ(a(1,1),2);
}
