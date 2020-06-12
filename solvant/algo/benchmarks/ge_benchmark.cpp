#include <benchmark/benchmark.h>

#include "algo/ge.hpp"

using namespace solvant;

static void ge_basic_solv(benchmark::State& state) {
    // Perform setup here
    vector<double, 100> rhs, x;
    matrix<double, 100, 100> A;
    for (std::size_t i = 0; i < 100; ++i) {
        for (std::size_t j = 0; j < 100; ++j) {
            A(i, j) = std::rand() / RAND_MAX;
        }
        rhs[i] = std::rand() / RAND_MAX;
    }

    for (auto _ : state) {
        ge(rhs, A, x);
    }
}

BENCHMARK(ge_basic_solv);
BENCHMARK_MAIN();
