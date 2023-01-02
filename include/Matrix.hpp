#pragma once
#include <vector>

namespace GameOfLife::Internal {
    class Matrix
    {
    public:
        Matrix(const std::vector<std::vector<int>> &matrix);
        int at(const int &row, const int &column);
       const std::vector<std::vector<int>> getData() const;
    private:
        std::vector<std::vector<int>> m_matrix;
    };
}