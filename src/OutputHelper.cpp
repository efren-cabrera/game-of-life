#include <iostream>
#include <Matrix.hpp>
#include <OutputHelper.hpp>

namespace GameOfLife {
    void OutputHelper::operator<<(const Internal::Matrix &matrix) {
        for (auto &row : matrix.getData())
        {
            for (auto value : row)
            {
                if (value == 0) {
                    std::cout << " ";
                }
                else {
                    std::cout << "█";
                }
            }
            std::cout << std::endl;
        }
    }
}