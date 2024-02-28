cmake_minimum_required(VERSION 3.28)
project(bobcpp)

set(CMAKE_CXX_STANDARD 26)

add_executable(bobcpp main.cpp
        command_maps.h)
