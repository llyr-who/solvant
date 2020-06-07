#include "algo/ge.hpp"

#include "core/matrix.hpp"
#include "core/vector.hpp"

#include "gtest/gtest.h"

template <std::size_t N>
using sq_matrix = solvant::matrix<double, N, N>;

template <std::size_t N>
using vector = solvant::vector<double, N>;

TEST(ge_test, basic_solv){
    sq_matrix<2> m = {1.0, 1.0, 3.0, -2.0};
    vector<2> v = {-9.0, 4.0};

    vector<2> soln = {-5.0,-5.0};

    vector<2> test;

    solvant::ge(v, m, soln);

    ASSERT_TRUE(test == soln);
}
