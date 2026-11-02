add_executable(moon_phase_example moon_phase_example.c)
add_executable(badluck badluck.c)
add_executable(matrix_multiply matrix_multiply_example.c)

target_link_libraries(moon_phase_example PRIVATE numrecipes::numrecipes)
target_link_libraries(badluck PRIVATE numrecipes::numrecipes)
target_link_libraries(matrix_multiply PRIVATE numrecipes::numrecipes)

find_package(Threads REQUIRED)
target_link_libraries(matrix_multiply PRIVATE Threads::Threads)
