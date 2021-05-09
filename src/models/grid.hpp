#pragma once

#include "models/case.hpp"
#include <vector>

struct Grid
{
    unsigned int height;
    unsigned int width;
    std::vector<std::vector<Case>> grid;
    Case &getCase(Coord const &coord);
    void reset();
    bool initilize(unsigned int xMax,
                   unsigned int yMax,
                   unsigned int numberOfColony);
    Grid();
};
