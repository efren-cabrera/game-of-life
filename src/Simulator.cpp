#include <Simulator.hpp>
#include <vector>
#include <numeric>
#include <thread>
#include <utility>
#include <execution>

namespace GameOfLife
{
	Internal::Matrix Simulator::getCurrentState()
	{
		return m_actual;
	}

	void Simulator::update()
	{
		auto lenght{ m_actual.getData().size() };
		unsigned long const minPerThread{ 25 };
		unsigned long const maxThreads = (lenght + minPerThread - 1) / (minPerThread);
		unsigned long const hardwareThreads{ std::thread::hardware_concurrency() };
		unsigned long const numThreads = std::min(hardwareThreads != 0 ? hardwareThreads : 2, maxThreads);
		unsigned long const blockSize = lenght / numThreads;
		std::vector<std::thread> threads{};

		std::vector<std::vector<int>> newState(m_actual.getSize().first);
		int nBlock{ 0 };

		std::vector<int> rowsBlock{};

		for (int rowIndex{ 0 }; rowIndex < m_actual.getSize().first; rowIndex++)
		{
			if (rowIndex % blockSize == 0)
			{
				if (rowIndex > 0)
				{
					threads.push_back(std::thread([this, rowsBlock, &newState]
						{ this->processBlock(rowsBlock, newState); }));
				}
				rowsBlock = std::vector<int>{};
				nBlock++;
			}
			rowsBlock.push_back(rowIndex);
		}
		if (rowsBlock.size() > 0)
		{
			threads.push_back(std::thread([this, rowsBlock, &newState]
				{ this->processBlock(rowsBlock, std::ref(newState)); }));
		}
		for (auto& thread : threads)
		{
			if (thread.joinable())
			{
				thread.join();
			}
		}
		m_actual = newState;
	}

	void Simulator::processBlock(std::vector<int> rowsBlock, std::vector<std::vector<int>>& newState)
	{
		for (auto& rowIndex : rowsBlock)
		{
			for (int columnIndex{ 0 }; columnIndex < m_actual.getSize().second; columnIndex++)
			{
				auto neighbors{ m_actual.getNeighbors(rowIndex, columnIndex) };
				auto currentState{ m_actual.getData()[rowIndex][columnIndex] };
				auto liveNeighbors = std::reduce(std::execution::par_unseq, neighbors.begin(), neighbors.end(), 0);
				auto state{ 0 };
				if (currentState == 1)
				{
					if (liveNeighbors >= m_neighborsThreshold && liveNeighbors <= m_neighborsThresholdMax)
					{
						state = 1;
					}
				}
				else
				{
					if (liveNeighbors == m_neighborsThresholdMax)
					{
						state = 1;
					}
				}
				newState[rowIndex].push_back(state);
			}
		}

	}
}