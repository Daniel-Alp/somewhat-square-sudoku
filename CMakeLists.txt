cmake_minimum_required(VERSION 3.17)
project (Sudoku)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

add_executable(Sudoku "src/main.cpp" "src/common.h" "src/helper.h" "src/helper.cpp" "src/sudoku.h" "src/sudoku.cpp")