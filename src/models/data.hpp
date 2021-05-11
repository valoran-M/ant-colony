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

    unsigned int lap;
    unsigned int width;
    unsigned int height;
    unsigned int numberOfColony;
    unsigned int caseSize;
    float speed;

    void addLap() { lap++; }
    void reset();

    Data();
};
