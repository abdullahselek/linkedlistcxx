cmake_minimum_required(VERSION 3.7)
project(linkedlistcxx)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp linkedlistcxx.h linkedlistcxx.cpp)
add_executable(linkedlistcxx ${SOURCE_FILES})