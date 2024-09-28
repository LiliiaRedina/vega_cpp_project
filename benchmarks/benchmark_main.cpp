#include <benchmark/benchmark.h>

#include "my_add.hpp"

static void BM_MyAdd(benchmark::State& state) {
    int a = 55;
    int b = 66;
    for (auto _ : state) {
        benchmark::DoNotOptimize(my_add(a, b));
    }
}

BENCHMARK(BM_MyAdd);

BENCHMARK_MAIN();