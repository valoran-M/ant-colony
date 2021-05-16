#pragma once

#include "models/colony.hpp"
#include "models/grid.hpp"

struct Data
{
    enum State
    {
        menu = 0,
        running = 1,
        paused = 2
    };

    State state;
    std::vector<Colony> colonies;
    std::vector<std::vector<Coord>> sugarPhero;

    Coord gridDim;
    unsigned int lap;
    unsigned int width;
    unsigned int height;
    unsigned int numberOfColony;
    unsigned int caseSize;
    unsigned int sugar;
    float speed;
    float decrease;

    void addLap() { lap++; }
    void reset();

    Data();
    Data(unsigned int colony,
         unsigned int sugar,
         int cellDim,
         Coord gridDim);
};
