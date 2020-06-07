#include "algo/ge.hpp"

#include <iostream>

#include "core/matrix.hpp"
#include "core/vector.hpp"
#include "gtest/gtest.h"

template <std::size_t N>
using sq_matrix = solvant::matrix<double, N, N>;

template <std::size_t N>
using vector = solvant::vector<double, N>;

TEST(ge_test, forward_substitute) {
    sq_matrix<2> m = {1.0, 0.0, 1.0, -2.0};
    vector<2> v = {1.0, 1.0};
    vector<2> soln = {1.0, 0.0};
    vector<2> test;
    solvant::forward_substitute(v, m, test);
    ASSERT_TRUE(test == soln);
}

TEST(ge_test, backward_substitute) {
    sq_matrix<2> m = {1.0, 1.0, 0.0, -2.0};
    vector<2> v = {1.0, 1.0};
    vector<2> soln = {1.5, -0.5};
    vector<2> test;
    solvant::backward_substitute(v, m, test);
    ASSERT_TRUE(test == soln);
}

TEST(ge_test, basic_solv) {
    sq_matrix<2> m = {1.0, 1.0, 3.0, -2.0};
    vector<2> v = {3.0, 4.0};

    vector<2> soln = {2.0, 1.0};

    vector<2> test;

    solvant::ge(v, m, test);

    std::cerr << "[          ] test = "
              << "(" << test[0] << "," << test[1] << ")" << std::endl;

    ASSERT_TRUE(test[0] == soln[0]);
    ASSERT_TRUE(test[1] == soln[1]);
}
