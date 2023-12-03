cmake_minimum_required(VERSION 3.26)
project(advent_of_code2023)

set(CMAKE_CXX_STANDARD 20)

add_executable(advent_of_code2023
        main.cpp
        day1/day1.h
        common.h
        day2/day2.h)

include_directories(advent_of_code2023 .)