/*
*  Check the at method, should return the value in corresponding [row, column]
*/

#include <iostream>
#include <vector>
#include <Matrix.hpp>

int main()
{
    std::cout << "Test starting" << std::endl;
    std::vector<std::vector<int>> testVector{{5, 6, 7}, {7, 4, 3}};
    GameOfLife::Internal::Matrix matrix = GameOfLife::Internal::Matrix(testVector);
    assert(matrix.at(1, 0) == 7);
    std::cout << "Test succeeded" << std::endl;
    return 0;
}