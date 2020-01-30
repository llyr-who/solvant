#include "gtest/gtest.h"
#include "solvant/base/banded_matrix.hpp"

template <std::size_t N>
using triband = solvant::base::banded_matrix<double, N, 3>;

template <std::size_t N>
using septband = solvant::base::banded_matrix<double, N, 7>;

template <std::size_t N>
using thirtband = solvant::base::banded_matrix<double, N, 13>;

TEST(banded_matrix, diagonal_constant_init) {
    triband<5> a({1, 2, 3});
    ASSERT_EQ(a(0, 0), 2);
    ASSERT_EQ(a(0, 1), 1);
    ASSERT_EQ(a(1, 0), 3);
    ASSERT_EQ(a(1, 1), 2);
}

TEST(banded_matrix, identity_matrix_multiplication) {
    septband<100> i({0, 0, 1, 0, 0});
    septband<100> b({1, 2, 1, 2, 0});
    // 2(7/2 + 7/2) + 1 = 2(6) + 1 = 13
    thirtband<100> c;

    matrix_prod(i, b, c);

    ASSERT_EQ(c(0, 0), 1);
}

