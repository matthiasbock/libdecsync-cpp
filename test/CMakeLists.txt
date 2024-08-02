
# Add your test executable
add_executable(run_tests main.cpp)

# Link against the 'decsync' library
target_link_libraries(run_tests PRIVATE decsync)

# Link the test executable with Boost.Test
target_link_libraries(run_tests PRIVATE Boost::unit_test_framework)
