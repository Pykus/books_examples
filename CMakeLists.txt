cmake_minimum_required(VERSION 3.14)
project(katas)
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(
    SoundexTest
    SoundexTest.cpp
)
target_link_libraries(
    SoundexTest
    gtest_main
)
include(GoogleTest)
gtest_discover_tests(SoundexTest)