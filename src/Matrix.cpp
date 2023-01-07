#include <vector>
#include <Matrix.hpp>

#include <iostream>
#include <format>

namespace GameOfLife::Internal {
    Matrix::Matrix(const std::vector<std::vector<int>> &matrix) : m_matrix{matrix} {
        size.first = m_matrix.size();
        size.second = m_matrix[0].size();
    };
    const int Matrix::at(const int &row, const int &column) const {
        return m_matrix.at(row).at(column);
    }
    const std::vector<std::vector<int>> Matrix::getData() const {
        return m_matrix;
    };
    const std::vector<int> Matrix::getNeighbors(const int &row, const int &column) const {
        std::vector<int> rows{row};
        std::vector<int> columns{column};
        std::vector<int> out{};

        if (row > 0) {
            rows.push_back(row - 1);
        }
        if (row < (size.first - 1)) {
            rows.push_back(row + 1);
        }

        if (column > 0) {
            columns.push_back(column - 1);
        }
        if (row < (size.second - 1)) {
            columns.push_back(column + 1);
        }

        for (int r{0}; r < rows.size(); r++) {
            for (int c{0}; c < columns.size(); c++) {
                if (r != row && c != column) {
                    out.push_back(this->at(r, c));
                }
            }
        }

        return out;
    }
}