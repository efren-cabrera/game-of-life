#pragma once
#include <iostream>
#include <Matrix.hpp>
#include <OutputHelper.hpp>

namespace GameOfLife {
    class OutputHelperConsole : public OutputHelper {
    public:
        void operator<<(const Internal::Matrix &matrix);
    };
}