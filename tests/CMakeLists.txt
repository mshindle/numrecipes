add_executable(test_misc test_misc.c)
target_link_libraries(test_misc PRIVATE numrecipes::numrecipes)
add_test(NAME test_misc COMMAND test_misc)

add_executable(test_util test_util.c)
target_link_libraries(test_util PRIVATE numrecipes::numrecipes)
add_test(NAME test_util COMMAND test_util)
set_tests_properties(test_util PROPERTIES
    WILL_FAIL TRUE
    PASS_REGULAR_EXPRESSION "Numerical Recipes run-time error"
)
