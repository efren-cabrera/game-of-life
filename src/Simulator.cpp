#include <Simulator.hpp>

namespace GameOfLife {
    Internal::Matrix Simulator::getCurrentState() {
        return m_actual;
    }
}