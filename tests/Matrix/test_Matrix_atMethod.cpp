/*
*  Check the at method, should return the value in corresponding [row, column]
*/

#include <vector>
#include <cassert>
#include <Matrix.hpp>
#include <cassert>

int main()
{
    std::vector<std::vector<int>> testVector{{5, 6, 7}, {7, 4, 3}};
    GameOfLife::Internal::Matrix matrix = GameOfLife::Internal::Matrix(testVector);
    assert(matrix.at(1, 0) == 7);
    return 0;
}