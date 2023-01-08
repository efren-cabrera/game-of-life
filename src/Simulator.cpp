#include <Simulator.hpp>
#include <vector>
#include <numeric>
#include <thread>
#include <utility>
#include <iostream>

namespace GameOfLife
{
    Internal::Matrix Simulator::getCurrentState()
    {
        return m_actual;
    }

    void Simulator::update()
    {
        unsigned long const lenght{m_actual.getData().size()};
        unsigned long const minPerThread{25};
        unsigned long const maxThreads{(lenght + minPerThread - 1) / (minPerThread)};
        unsigned long const hardwareThreads{std::thread::hardware_concurrency()};
        unsigned long const numThreads = std::min(hardwareThreads != 0 ? hardwareThreads : 2, maxThreads);
        unsigned long const blockSize = lenght / numThreads;
        std::vector<std::thread> threads;

        std::vector<std::vector<int>> newState{};
        int nBlock{0};

        std::vector<int> block{};

        for (int r{0}; r < m_actual.getData().size(); r++)
        {
            newState.push_back(std::vector<int>{});
            if (r % blockSize == 0)
            {
                if (r > 0)
                {
                    std::cout << r << ". Starting new thread" << std::endl;
                    threads.push_back(std::thread([this, block, &newState]
                                                  { this->processBlock(block, newState); }));
                }
                block = std::vector<int>{};
                nBlock++;
            }
            block.push_back(r);
        }
        std::cout << nBlock * blockSize << std::endl;
        if ((nBlock * blockSize) <= lenght)
        {
            std::cout << ". Starting new thread" << std::endl;
            threads.push_back(std::thread([this, block, &newState]
                                          { this->processBlock(block, std::ref(newState)); }));
        }
        for (auto &t : threads)
        {
            if (t.joinable())
            {
                t.join();
            }
        }
        m_actual = newState;
    }

    void Simulator::processBlock(std::vector<int> block, std::vector<std::vector<int>> &newState)
    {
        for (int i{0}; i < block.size(); i++)
        {
            auto r{block[i]};
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
    }
}