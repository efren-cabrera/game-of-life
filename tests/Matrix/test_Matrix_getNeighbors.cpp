/*
* Check that getNeighbors return expected values
*/

#include <vector>
#include <cassert>
#include <Matrix.hpp>
#include <cassert>
#include <array>

int main()
{
    std::vector<std::vector<int>> testVector{{5, 6, 7}, {7, 4, 3}};
    GameOfLife::Internal::Matrix matrix = GameOfLife::Internal::Matrix(testVector);
    std::array<int, 8> v1{0, 0, 0, 0, 0, 6, 7, 4};
    assert(matrix.getNeighbors(0, 0) == v1);

    std::array<int, 8> v2{0, 0, 0, 5, 7, 7, 4, 3};
    assert(matrix.getNeighbors(0, 1) == v2);
    return 0;
}