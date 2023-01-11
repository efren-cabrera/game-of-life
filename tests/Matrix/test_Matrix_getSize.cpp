/*
* Check that the the getSize method return the expected size
*/

#include <iostream>
#include <vector>
#include <Matrix.hpp>

int main()
{
    std::cout << "Test starting" << std::endl;
    std::vector<std::vector<int>> testVector{{5, 6, 7}, {7, 4, 3}};
    GameOfLife::Internal::Matrix matrix = GameOfLife::Internal::Matrix(testVector);
    assert(matrix.getSize().first == 2);
    assert(matrix.getSize().second == 3);
    std::cout << "Test succeeded" << std::endl;
    return 0;
}