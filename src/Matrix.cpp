#include <vector>
#include <Matrix.hpp>

namespace GameOfLife::Internal
{
    Matrix::Matrix(const std::vector<std::vector<int>> &matrix) : m_matrix{matrix}
    {
        size.first = matrix.size();
        size.second = matrix[0].size();
    };
    const int Matrix::at(const int &row, const int &column) const
    {
        return m_matrix.at(row).at(column);
    }
    const std::vector<std::vector<int>> Matrix::getData() const
    {
        return m_matrix;
    };
    const std::vector<int> Matrix::getNeighbors(const int &row, const int &column) const
    {
        std::vector<int> rows{};
        std::vector<int> columns{};
        std::vector<int> out{};

        if (row > 0)
        {
            rows.push_back(row - 1);
        }
        rows.push_back(row);
        if (row < (size.first - 1))
        {
            rows.push_back(row + 1);
        }

        if (column > 0)
        {
            columns.push_back(column - 1);
        }
        columns.push_back(column);
        if (column < (size.second - 1))
        {
            columns.push_back(column + 1);
        }
        for (auto &r : rows)
        {
            for (auto &c : columns)
            {
                if (r == row && c == column)
                {
                    continue;
                }
                out.push_back(this->at(r, c));
            }
        }
        return out;
    }
}