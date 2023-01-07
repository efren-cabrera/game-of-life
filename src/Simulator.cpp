#include <Simulator.hpp>
#include <vector>
#include <numeric>

namespace GameOfLife
{
    Internal::Matrix Simulator::getCurrentState()
    {
        return m_actual;
    }
    void Simulator::update()
    {
        std::vector<std::vector<int>> newState{};
        for (int r{0}; r < m_actual.getData().size(); r++)
        {
            newState.push_back(std::vector<int>{});
            for (int c{0}; c < m_actual.getData()[r].size(); c++)
            {
                auto neighbors{m_actual.getNeighbors(r, c)};
                auto liveNeighbors = std::accumulate(neighbors.begin(), neighbors.end(), 0);
                auto state{0};
                if (liveNeighbors >= m_neighborsThreshold)
                {
                    state = 1;
                }
                newState[r].push_back(state);
            }
        }
        m_actual = newState;
    }
}