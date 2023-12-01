cmake_minimum_required(VERSION 3.26)
project(advent_of_code2023)

set(CMAKE_CXX_STANDARD 20)

add_executable(advent_of_code2023 day1/main.cpp
        common.h)

include_directories(advent_of_code2023 .)