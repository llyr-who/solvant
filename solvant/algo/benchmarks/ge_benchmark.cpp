#include <benchmark/benchmark.h>

static void ge_basic_solv(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    // ...
  }
}

BENCHMARK(ge_basic_solv);
BENCHMARK_MAIN();
