#pragma once

#include "models/case.hpp"
#include <vector>


struct Grid
{
    std::size_t height;
    std::size_t width;
    std::vector<std::vector<Case>> grid;
    void reset();
    bool initilize(std::size_t xMax,
                   std::size_t yMax);
    Grid();
};
