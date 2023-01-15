/*
* Check that getNeighbors return expected values
*/

#include <iostream>
#include <vector>
#include <Matrix.hpp>
#include <cassert>
#include <array>

int main()
{
    std::cout << "Test starting" << std::endl;
    std::vector<std::vector<int>> testVector{{5, 6, 7}, {7, 4, 3}};
    GameOfLife::Internal::Matrix matrix = GameOfLife::Internal::Matrix(testVector);
    std::array<int, 8> v1{0, 0, 0, 0, 0, 6, 7, 4};
    assert(matrix.getNeighbors(0, 0) == v1);

    std::array<int, 8> v2{0, 0, 0, 5, 7, 7, 4, 3};
    assert(matrix.getNeighbors(0, 1) == v2);
    std::cout << "Test succeeded" << std::endl;
    return 0;
}