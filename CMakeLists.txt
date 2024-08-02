# CMake minimum version requirement
cmake_minimum_required(VERSION 3.10)

# Project name
project(DecSync)

# Find Boost and specifically Boost.Test
find_package(
    Boost
    REQUIRED
    COMPONENTS
    unit_test_framework
)

# Check if ccache is available
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    message(STATUS "Using ccache for compilation")
    set(CMAKE_C_COMPILER_LAUNCHER ccache)
    set(CMAKE_CXX_COMPILER_LAUNCHER ccache)
else()
    message(STATUS "ccache not found")
endif()

# Add source directory for the main code
add_subdirectory(src)

# Add test directory
add_subdirectory(test)

