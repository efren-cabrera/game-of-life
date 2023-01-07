#pragma once
#include <Matrix.hpp>
#include <OutputHelper.hpp>
#include <string>

namespace GameOfLife
{
    class OutputHelperPPM : public OutputHelper
    {
    public:
        OutputHelperPPM(std::string baseFileName) : m_baseFileName{baseFileName} {};
        void operator<<(const Internal::Matrix &matrix);

    private:
        std::string m_baseFileName;
        int currentKeyframe{0};
    };
}