#pragma once
#include <iostream>
#include <Matrix.hpp>
#include <OutputHelper.hpp>

namespace GameOfLife {
    class OutputHelperPPM : public OutputHelper {
    public:
        void operator<<(const Internal::Matrix &matrix);
    };
}