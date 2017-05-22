cmake_minimum_required(VERSION 3.0)
project(linkedlistcxx)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(source)

enable_testing()
add_subdirectory(test)

#add_test(linkedlistcxxtests tests COMMAND Test)
#
#set(SOURCE_FILES main.cpp include/linkedlistcxx.h source/linkedlistcxx.cpp test/linkedlistcxx-tests.cpp)
#add_executable(linkedlistcxx ${SOURCE_FILES})
