cmake_minimum_required(VERSION 3.10)
project(myStack CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include(cmake/GTest.cmake)

add_executable(myCollectionsTests src/myStackTest.cpp src/myQueueTest.cpp)
target_include_directories(myCollectionsTests PUBLIC include)
target_link_libraries(myCollectionsTests gtest_main gtest)

enable_testing()
add_test(tests myCollectionsTests)