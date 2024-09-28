cmake_minimum_required(VERSION 3.14)
project(vega_cpp_course)

include_directories(include)

add_executable(main main.cpp src/my_add.cpp)
# add_subdirectory(benchmarks)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark
    GIT_TAG v1.9.0
)
FetchContent_MakeAvailable(googlebenchmark)

enable_testing()
add_executable(tests test_add.cpp src/my_add.cpp)
add_executable(my_benchmark benchmarks/benchmark_main.cpp src/my_add.cpp)
target_link_libraries(tests gtest_main)
target_link_libraries(my_benchmark PRIVATE benchmark::benchmark)

include(GoogleTest)
# include(GoogleBenchmark)
# gtest_discover_test(tests)