cmake_minimum_required(VERSION 3.16)
project(TicTacToe_tests)

set(CMAKE_CTicTacToe_STANDARD 17)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}})

add_executable(TicTacToe_tests_run TicTacToeTest.cpp)

target_link_libraries(TicTacToe_tests_run TicTacToe_lib)

target_link_libraries(TicTacToe_tests_run gtest gmock gtest_main)
