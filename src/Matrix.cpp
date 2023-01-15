#include <vector>
#include <Matrix.hpp>
#include <array>
#include <stdexcept>

namespace GameOfLife::Internal
{
	Matrix::Matrix(const std::vector<std::vector<int>>& matrix) : m_matrix{ matrix }
	{
		size.first = matrix.size();
		size.second = matrix[0].size();
	};
	const int Matrix::at(const int& row, const int& column) const
	{
		try {
			return m_matrix.at(row).at(column);
		}
		catch (const std::out_of_range& oor) {
			return 0;
		}
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