project(Persistence_representations_example)

add_executable ( Persistence_representations_example_landscape_on_grid persistence_landscape_on_grid.cpp )
add_test(NAME Persistence_representations_example_landscape_on_grid
    COMMAND $<TARGET_FILE:Persistence_representations_example_landscape_on_grid>)
install(TARGETS Persistence_representations_example_landscape_on_grid DESTINATION bin)

add_executable ( Persistence_representations_example_landscape persistence_landscape.cpp )
add_test(NAME Persistence_representations_example_landscape
    COMMAND $<TARGET_FILE:Persistence_representations_example_landscape>)
install(TARGETS Persistence_representations_example_landscape DESTINATION bin)

add_executable ( Persistence_representations_example_intervals persistence_intervals.cpp )
add_test(NAME Persistence_representations_example_intervals
    COMMAND $<TARGET_FILE:Persistence_representations_example_intervals>
    "${CMAKE_SOURCE_DIR}/data/persistence_diagram/first.pers")
install(TARGETS Persistence_representations_example_intervals DESTINATION bin)

add_executable ( Persistence_representations_example_vectors persistence_vectors.cpp )
add_test(NAME Persistence_representations_example_vectors
    COMMAND $<TARGET_FILE:Persistence_representations_example_vectors>)
install(TARGETS Persistence_representations_example_vectors DESTINATION bin)

add_executable ( Persistence_representations_example_heat_maps persistence_heat_maps.cpp )
add_test(NAME Persistence_representations_example_heat_maps
    COMMAND $<TARGET_FILE:Persistence_representations_example_heat_maps>)
install(TARGETS Persistence_representations_example_heat_maps DESTINATION bin)

add_executable ( Sliced_Wasserstein sliced_wasserstein.cpp )
add_test(NAME Sliced_Wasserstein
    COMMAND $<TARGET_FILE:Sliced_Wasserstein>)
install(TARGETS Sliced_Wasserstein DESTINATION bin)
