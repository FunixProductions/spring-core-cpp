# Add test executable
add_executable(FunixProductionsCoreTests funixproductions_core_tests.cpp)

# Link the library to the test executable
target_link_libraries(FunixProductionsCoreTests PRIVATE FunixProductionsCore)

# Add the test
add_test(NAME FunixProductionsCoreTests COMMAND FunixProductionsCore)