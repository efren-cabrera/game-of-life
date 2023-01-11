include(CTest)

add_executable(TestMatrixAdd Matrix/test_Matrix_atMethod.cpp)
add_executable(TestMatrixGetSize Matrix/test_Matrix_getSize.cpp)
add_executable(TestMatrixGetNeighbors Matrix/test_Matrix_getNeighbors.cpp)

target_link_libraries(TestMatrixAdd PUBLIC GameofLifeInternal)
target_link_libraries(TestMatrixGetSize PUBLIC GameofLifeInternal)
target_link_libraries(TestMatrixGetNeighbors PUBLIC GameofLifeInternal)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    add_subdirectory(MyLibTests)
endif ()

add_test(NAME TestMatrixAdd COMMAND TestMatrixAdd)
add_test(NAME TestMatrixGetSize COMMAND TestMatrixGetSize)
add_test(NAME TestMatrixGetNeighbors COMMAND TestMatrixGetNeighbors)

enable_testing()