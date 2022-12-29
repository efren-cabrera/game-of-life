#pragma once
#include <vector>

class Matrix
{
public:
    Matrix(const std::vector<std::vector<int>> matrix);

    const void printMatrix() const;

private:
    std::vector<std::vector<int>> m_matrix;
};