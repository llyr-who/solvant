#include "solvant/base/tridiagonal_matrix.hpp"
#include "gtest/gtest.h"

using tri_matrix4  = solvant::base::tridiagonal_matrix<double, 4>;

TEST(tridiagonal, init) {
    tri_matrix4 a({1,2,3});
}
