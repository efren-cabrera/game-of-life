#pragma once
#include <Matrix.hpp>
#include <random>

namespace GameOfLife::Utils
{
    class MatrixInitializer
    {
    public:
        MatrixInitializer();
        Internal::Matrix createMatrix(int &nRows, int &nColumns);
    private:
        std::mt19937 m_engine;
        std::uniform_int_distribution<int> m_distribution{1, 100};
    };
}