#include "solvant/solver/thomas.hpp"

#include "gtest/gtest.h"
#include "solvant/base/tridiagonal_matrix.hpp"

template <std::size_t N>
using tridiag = solvant::base::tridiagonal_matrix<double, N>;

TEST(thomas, basic_solv) {
    // identiy
    tridiag<5> I({0, 1, 0});
    std::array<double, 5> rhs, x;
    rhs = {1, 1, 1, 1, 1};
    solvant::solver::thomas(rhs, I, x);
    ASSERT_TRUE(rhs == x);
}

