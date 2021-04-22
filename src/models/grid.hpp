#pragma once

#include <vector>

#include "models/case.hpp"

struct Grid
{
    std::size_t height;
    std::size_t width;
    std::vector<std::vector<Case>> grid;
    void reset();
    bool intialise(std::size_t xMax,
                   std::size_t yMax,
                   std::size_t numberColony);
    Grid();
};
