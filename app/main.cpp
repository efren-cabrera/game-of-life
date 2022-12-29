#include <iostream>
#include <vector>

#include <Matrix.hpp>

int main()
{
    std::vector<std::vector<int>> testVector{{5, 6, 7}, {7, 4, 3}};
    Matrix matrix = Matrix(testVector);
    matrix.printMatrix();
    return 0;
}