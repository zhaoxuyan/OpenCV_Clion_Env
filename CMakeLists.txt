cmake_minimum_required(VERSION 3.8)
project(opencv_test1)

set(CMAKE_CXX_STANDARD 11)

#find_library(OpenCV)
find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

add_executable(opencv_test1 main.cpp)
target_link_libraries(opencv_test1 ${OpenCV_LIBS})