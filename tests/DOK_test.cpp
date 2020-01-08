#include "solvant/base/DOK_matrix.hpp"
#include "gtest/gtest.h"

using DOK_matrix  = solvant::sparse::DOK_matrix<double>;

TEST(matrix, matrix_square) {
    DOK_matrix a;
    a.add_entry(0,0,1.0);
    a.add_entry(1,1,1.0);
}

