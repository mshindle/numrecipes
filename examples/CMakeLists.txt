add_executable(moon_phase_example moon_phase_example.c)
add_executable(badluck badluck.c)

target_link_libraries(moon_phase_example PRIVATE numrecipes::numrecipes)
target_link_libraries(badluck PRIVATE numrecipes::numrecipes)
