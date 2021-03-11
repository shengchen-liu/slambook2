cmake_minimum_required(VERSION 2.8)

# set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_BUILD_TYPE "Debug")

# add support for c++11 
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")

# Eigen
include_directories("/usr/incldue/eigen3")

# Find OpenCV package
find_package(OpenCV REQUIRED)

# include header files
include_directories(${OpenCV_INCLUDE_DIRS})

# subdirectory
add_subdirectory(imageBasics)
# add_subdirectory(stereo)
# add_subdirectory(rgbd)