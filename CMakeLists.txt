cmake_minimum_required(VERSION 3.0)
project(linkedlistcxx)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

include(cmake/DownloadProject.cmake)
download_project(PROJ       googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

set(SOURCE_FILES main.cpp linkedlistcxx.h linkedlistcxx.cpp test/linkedlistcxx-tests.cpp)
add_executable(linkedlistcxx ${SOURCE_FILES})
target_link_libraries(linkedlistcxx gtest gmock_main)

################################
# Unit Tests
################################
# Add test cpp file
add_executable(tests test/linkedlistcxx-tests.cpp)
add_test(tests tests)
target_link_libraries(tests gtest gmock_main)
