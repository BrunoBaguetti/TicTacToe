cmake_minimum_required(VERSION 3.16)
project(Setup)

set(CMAKE_CTicTacToe_STANDARD 17)
set(CMAKE_CTicTacToe_VISIBILITY_PRESET hidden)

add_executable(TicTacToe_run main.cpp)

include_directories(TicTacToe_files)
add_subdirectory(TicTacToe_files)

target_link_libraries(TicTacToe_run TicTacToe_lib)

add_subdirectory(Google_tests)
