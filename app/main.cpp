#include <iostream>
#include <vector>

#include <Matrix.hpp>
#include <Simulator.hpp>
#include <OutputHelper.hpp>
#include <OutputHelperPPM.hpp>
#include <MatrixInitializer.hpp>

#include <thread>

int main()
{
    GameOfLife::Utils::MatrixInitializer init{};
    auto rows{150};
    auto columns{200};
    auto percentageOfDeathCells = .96;

    GameOfLife::Internal::Matrix initialStateMatrix{init.createMatrix(rows, columns, percentageOfDeathCells)};
    GameOfLife::Simulator simulator = GameOfLife::Simulator(initialStateMatrix);
    GameOfLife::OutputHelper *outPPM = new GameOfLife::OutputHelperPPM("out/test");

    for (int i{0}; i < 50; i++) {
        *outPPM << simulator.getCurrentState();
        simulator.update();
        std::cout << "Frame " << i + 1 << " done." << std::endl;
        std::cout << "--------------------" << std::endl;
    }

    return 0;
}