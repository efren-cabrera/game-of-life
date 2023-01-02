#include <Matrix.hpp>

namespace GameOfLife::Internal {
    Matrix::Matrix(const std::vector<std::vector<int>> &matrix) : m_matrix{matrix} {};
    int Matrix::at(const int &row, const int &column) {
        return m_matrix.at(row).at(column);
    }
    const std::vector<std::vector<int>> Matrix::getData() const {
        return m_matrix;
    };
}