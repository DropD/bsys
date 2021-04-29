cmake_minimum_required(VERSION 3.14)
project(gtest_simple)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(square_plus_one_test tests/test_square_plus_one.cpp)
target_link_libraries(square_plus_one_test gtest_main)

include(GoogleTest)
gtest_discover_tests(square_plus_one_test)
