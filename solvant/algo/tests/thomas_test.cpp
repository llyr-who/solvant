#include "solvant/algo/thomas.hpp"
#include "solvant/core/tridiagonal_matrix.hpp"

#include "gtest/gtest.h"

template <std::size_t N>
using tridiag = solvant::tridiagonal_matrix<double, N>;

TEST(thomas, basic_solv) {
    // identiy
    tridiag<5> I({0, 1, 0});
    std::array<double, 5> rhs, x;
    rhs = {1, 1, 1, 1, 1};
    solvant::thomas(rhs, I, x);
    ASSERT_TRUE(rhs == x);
}

