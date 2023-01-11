/*
* Check that the the getSize method return the expected size
*/

#include <vector>
#include <cassert>
#include <Matrix.hpp>

int main()
{
    std::vector<std::vector<int>> testVector{{5, 6, 7}, {7, 4, 3}};
    GameOfLife::Internal::Matrix matrix = GameOfLife::Internal::Matrix(testVector);
    assert(matrix.getSize().first == 2);
    assert(matrix.getSize().second == 3);
    return 0;
}