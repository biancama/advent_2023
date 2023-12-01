cmake_minimum_required(VERSION 3.26)
project(advent_2023)

set(CMAKE_CXX_STANDARD 17)

add_executable(advent_2023 main.cpp
        src/utils/ReadFile.cpp
        src/utils/ReadFile.h
        src/01/CalibrationValue.cpp
        src/01/CalibrationValue.h)
