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
    std::cerr << "[          ] soln = "
              << "(" << soln[0] << "," << soln[1] << ")" << std::endl;
    std::cerr << "[          ] test = "
              << "(" << test[0] << "," << test[1] << ")" << std::endl;
    ASSERT_NEAR(test[0], soln[0], 1e-4);
    ASSERT_NEAR(test[1], soln[1], 1e-4);

    // clang-format off
    sq_matrix<3> m1 = {1.0, 1.0 , 3.0, 
                      -2.0, 1.0 , 10.0,
                      10.0, 11.0, 12.0};
    // clang-format on

    vector<3> v1 = {3.0, 4.0, -2.0};
    vector<3> soln1 = {3.2, -4.742857142857143, 1.5142857142857142};
    vector<3> test1;
    solvant::ge(v1, m1, test1);
    std::cerr << "[          ] soln1 = "
              << "(" << soln1[0] << "," << soln1[1] << "," << soln1[2] << ")"
              << std::endl;
    std::cerr << "[          ] test1 = "
              << "(" << test1[0] << "," << test1[1] << "," << test1[2] << ")"
              << std::endl;
    ASSERT_NEAR(test1[0], soln1[0], 1e-4);
    ASSERT_NEAR(test1[1], soln1[1], 1e-4);
    ASSERT_NEAR(test1[2], soln1[2], 1e-4);

    // clang-format off
    sq_matrix<3> m2 = {1.0, 1.0 , 3.0, 
                      -2.0, 0.0 , 10.0,
                      10.0, 11.0, 0.0};
    // clang-format on

    vector<3> v2 = {3.0, 4.0, -2.0};
    vector<3> soln2 = {2.8684210526315788, -2.789473684210526,
                       0.9736842105263158};
    vector<3> test2;
    solvant::ge(v2, m2, test2);
    ASSERT_NEAR(test2[0], soln2[0], 1e-4);
    ASSERT_NEAR(test2[1], soln2[1], 1e-4);
    ASSERT_NEAR(test2[2], soln2[2], 1e-4);
}
