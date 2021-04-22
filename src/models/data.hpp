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

    std::size_t lap;
    std::size_t speed;

    void addLap() { lap++; }
    void reset();

    Data();
};
