#include "core/vector.hpp"
#include "gtest/gtest.h"

template <std::size_t N>
using vector = solvant::vector<double, N>;

TEST(vector, dot) {
    vector<4> a = {1.0, 2.0, 3.0, 4.0};
    vector<4> b = {1.0, 2.0, 3.0, 4.0};

    ASSERT_TRUE(a*b == 30);
}

TEST(vector, cross) {
    vector<3> a = {1.0, 1.0, 1.0};
    vector<3> b = {4.0, 5.0, 6.0};
    vector<3> c;
    vector<3> d = {1.0,-2.0,1.0};
    solvant::cross3(a,b,c);

    ASSERT_EQ(c,d);
}

