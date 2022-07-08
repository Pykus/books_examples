cmake_minimum_required(VERSION 3.14)
project(tdd)
set(CMAKE_CXX_STANDARD 17)


include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#add_compile_options(--coverage)

#add_compile_options(-g)
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
add_custom_target(bir COMMAND SoundexTest)
