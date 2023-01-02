#pragma once
#include <iostream>
#include <Matrix.hpp>

namespace GameOfLife {
    class OutputHelper {
    public:
        void operator<<(const Internal::Matrix &matrix);
    };
}