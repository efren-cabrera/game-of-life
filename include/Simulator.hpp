#pragma once
#include <Matrix.hpp>

namespace GameOfLife {
    class Simulator {
    public:
        Simulator(Internal::Matrix &intialState) : m_actual{intialState} {};
        Internal::Matrix getCurrentState();
        void update();
    private:
        Internal::Matrix m_actual;
        const int m_neighborsThreshold{3};
    };
}