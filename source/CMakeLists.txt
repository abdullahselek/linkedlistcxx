cmake_minimum_required(VERSION 3.0)

add_library(linkedlistcxx ../include/linkedlistcxx.h linkedlistcxx.cpp)
add_executable(demo ../main.cpp)
