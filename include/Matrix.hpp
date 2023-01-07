#pragma once
#include <vector>
#include <utility>

namespace GameOfLife::Internal {
    class Matrix
    {
    public:
        Matrix(const std::vector<std::vector<int>> &matrix);
        const int at(const int &row, const int &column) const;
        const std::vector<std::vector<int>> getData() const;
        const std::vector<int> getNeighbors(const int &row, const int &column) const;
        const std::pair<int, int> getSize() const { return size; }
    private:
        std::vector<std::vector<int>> m_matrix;
        std::pair<int, int> size;
    };
}