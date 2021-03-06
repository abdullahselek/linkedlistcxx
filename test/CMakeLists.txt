cmake_minimum_required(VERSION 3.0)

include(../cmake/DownloadProject.cmake)
download_project(PROJ       googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
include_directories(../source/)

# Add test cpp file
add_executable(tests linkedlistcxx-tests.cpp linkedlistcxxint-tests.cpp linkedlistcxxchar-tests.cpp main.cpp)
target_link_libraries(tests linkedlistcxx gtest gmock_main)
add_test(tests tests COMMAND Test)
