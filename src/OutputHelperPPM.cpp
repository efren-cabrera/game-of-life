#include <Matrix.hpp>
#include <OutputHelperPPM.hpp>
#include <fstream>

namespace GameOfLife
{
    void OutputHelperPPM::operator<<(const Internal::Matrix &matrix)
    {
        auto dimY = matrix.getSize().first;
        auto dimX = matrix.getSize().second;
        std::string fileName{m_baseFileName + "_" + std::to_string(currentKeyframe) + ".ppm"};
        std::ofstream ofs(fileName, std::ios_base::out | std::ios_base::binary);

        ofs << "P6" << std::endl
            << dimX << ' ' << dimY << std::endl
            << "255" << std::endl;

        for (auto row : matrix.getData())
        {
            for (auto column : row)
            {
                if (column == 1)
                {
                    // red, green, blue
                    ofs << (char)(61) << (char)(166) << (char)(63);
                }
                else
                {
                    ofs << (char)(0) << (char)(0) << (char)(0);
                }
            }
        }

        ofs.close();
        currentKeyframe++;
    }

}