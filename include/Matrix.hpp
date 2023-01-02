#pragma once
#include <vector>

class Matrix
{
public:
    Matrix(const std::vector<std::vector<int>> matrix);
    const void printMatrix() const;
    int at(const int &row, const int &column);

private:
    std::vector<std::vector<int>> m_matrix;
};