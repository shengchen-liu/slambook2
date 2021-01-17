# declare the minimum version of cmake
cmake_minimum_required(VERSION 2.8)

# cmake project
project(HelloSLAM)

# cmake build type
set(CMAKE_BUILD_TYPE "Debug")

# add an executable
# dd_executable( projet name source code ）
add_executable(helloSLAM helloSLAM.cpp)

# add library "libHelloSlam"
add_library(hello libHelloSLAM.cpp)
# add shared library
add_library(hello_shared SHARED libHelloSLAM.cpp)

# 添加可执行程序调用hello库中函数
add_executable(useHello useHello.cpp)
# 将库文件链接到可执行程序上
target_link_libraries(useHello hello_shared)
