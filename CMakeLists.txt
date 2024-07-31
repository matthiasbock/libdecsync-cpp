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

# Add source directory for the main code
add_subdirectory(src)

# Add test directory
add_subdirectory(test)

