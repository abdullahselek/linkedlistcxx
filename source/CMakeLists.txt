cmake_minimum_required(VERSION 3.0)

include_directories(../include)
add_library(linkedlistcxx linkedlistcxx.cpp)
add_executable(demo ../main.cpp)
