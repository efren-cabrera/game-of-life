#pragma once
#include <iostream>
#include <Matrix.hpp>

namespace GameOfLife
{
    class OutputHelper
    {
    public:
        virtual void operator<<(const Internal::Matrix &matrix) = 0;
    };
}