#pragma once
#include <vector>

#include "models/case.hpp"

struct Grid
{
    std::size_t height;
    std::size_t width;
    std::vector<std::vector<Case>> grid;
    Grid(std::size_t height,
         std::size_t width,
         std::size_t numberColony);
    ~Grid();
};
