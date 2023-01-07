#include <iostream>
#include <Matrix.hpp>
#include <OutputHelperConsole.hpp>

namespace GameOfLife
{
    void OutputHelperConsole::operator<<(const Internal::Matrix &matrix)
    {
        for (auto &row : matrix.getData())
        {
            std::cout << "|";
            for (auto value : row)
            {
                if (value == 0)
                {
                    std::cout << " ";
                }
                else
                {
                    std::cout << "█";
                }
            }
            std::cout << "|";
            std::cout << std::endl;
        }
    }
}