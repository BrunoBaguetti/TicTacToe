cmake_minimum_required(VERSION 3.16)
project(Google_tests)

add_subdirectory(TicTacToe_tests)

include(FetchContent)
FetchContent_Declare(
        lib
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(lib)

set(CMAKE_CTicTacToe_STANDARD 17)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}})

