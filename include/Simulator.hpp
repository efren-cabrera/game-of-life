#pragma once
#include <Matrix.hpp>

namespace GameOfLife {
    class Simulator {
    public:
        Simulator(Internal::Matrix &intialState) : m_actual{intialState} {};
        Internal::Matrix getCurrentState();
    private:
        Internal::Matrix m_actual;
    };
}