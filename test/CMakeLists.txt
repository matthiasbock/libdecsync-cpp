
# Add your test executable
add_executable(DecSyncTests main.cpp)

# Link against the 'decsync' library
target_link_libraries(DecSyncTests PRIVATE decsync)

# Link the test executable with Boost.Test
target_link_libraries(DecSyncTests PRIVATE Boost::unit_test_framework)
