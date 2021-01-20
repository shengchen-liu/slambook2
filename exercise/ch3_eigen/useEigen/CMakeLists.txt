cmake_minimum_required(VERSION 2.8)
project(useEigen)

# set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-O3")

# add Eigen headers
include_directories("/usr/include/eigen3")
add_executable(eigenMatrix eigenMatrix.cpp)