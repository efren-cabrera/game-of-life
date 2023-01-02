#include <Matrix.hpp>

#include <iostream>

Matrix::Matrix(const std::vector<std::vector<int>> matrix) : m_matrix{matrix} {};

const void Matrix::printMatrix() const
{
    for (auto row : m_matrix)
    {
        for (auto value : row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int Matrix::at(const int &row, const int &column) {
    return m_matrix.at(row).at(column);
}
