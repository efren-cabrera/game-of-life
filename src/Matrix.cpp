#include <vector>
#include <Matrix.hpp>
#include <array>

namespace GameOfLife::Internal
{
	Matrix::Matrix(const std::vector<std::vector<int>>& matrix) : m_matrix{ matrix }
	{
		size.first = matrix.size();
		size.second = matrix[0].size();
	};
	const int Matrix::at(const int& row, const int& column) const
	{
		if (row < 0 || column < 0 || row >= size.first || column >= size.second)
		{
			return 0;
		}
		return m_matrix.at(row).at(column);
	}
	const std::vector<std::vector<int>> Matrix::getData() const
	{
		return m_matrix;
	};
	const std::array<int, 8> Matrix::getNeighbors(const int& row, const int& column) const
	{
		std::array<int, 8> out{
			this->at(row - 1, column - 1),
			this->at(row - 1, column),
			this->at(row - 1, column + 1),
			this->at(row, column - 1),
			this->at(row, column + 1),
			this->at(row + 1, column - 1),
			this->at(row + 1, column),
			this->at(row + 1, column + 1),
		};
		return out;
	}
}