cmake_minimum_required(VERSION 3.20)

project(Vector LANGUAGES CXX)

add_library(Vector INTERFACE)

target_include_directories(
    Vector
    INTERFACE
    include
)

target_compile_features(
    Vector
    INTERFACE
    cxx_std_20
)

add_executable(MyApp
    examples/main.cpp
)

target_link_libraries(
    MyApp
    PRIVATE
    Vector
)



include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.16.0
)

FetchContent_MakeAvailable(googletest)

add_executable(VectorTests tests/vector_tests.cpp)
target_link_libraries(VectorTests PRIVATE Vector GTest::gtest_main)

enable_testing()

include(GoogleTest)

gtest_discover_tests(VectorTests)