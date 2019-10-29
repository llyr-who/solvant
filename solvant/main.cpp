#include <iostream>
#include "base/matrix.hpp"
int main(int argc, const char* argv[]) {
	solvant::base::matrix<double, 10,10> A;
	solvant::base::matrix<double, 10,10> B;
	auto C = A*B;
}
