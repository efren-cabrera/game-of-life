#include <vector>
#include <Matrix.hpp>
#include <random>
#include <MatrixInitializer.hpp>

namespace GameOfLife::Utils
{
    MatrixInitializer::MatrixInitializer()
    {
        std::random_device seeder;
        const auto seed{seeder.entropy() ? seeder() : time(nullptr)};
        m_engine = std::mt19937(seed);
    }
    Internal::Matrix MatrixInitializer::createMatrix(int &nRows, int &nColumns, double fraction)
    {
        std::vector<std::vector<int>> out;
        for (int r{0}; r < nRows;r++)
        {
            out.push_back(std::vector<int>{});
            for (int c{0}; c < nColumns; c++)
            {
                auto number = m_distribution(m_engine);
                if (number < (fraction*100))
                {
                    out[r].push_back(0);
                }
                else
                {
                    out[r].push_back(1);
                }
            }
        }
        return Internal::Matrix(out);
    }
}