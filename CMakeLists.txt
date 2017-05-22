cmake_minimum_required(VERSION 3.0)
project(linkedlistcxx)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(source)

enable_testing()
add_subdirectory(test)
