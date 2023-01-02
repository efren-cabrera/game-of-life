add_executable(GameOfLife main.cpp)

target_link_libraries(GameOfLife PUBLIC Matrix)
target_link_libraries(GameOfLife PUBLIC Simulator)
target_link_libraries(GameOfLife PUBLIC Output)