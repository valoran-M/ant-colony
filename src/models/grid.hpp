#pragma once
#include <vector>

#include "models/case.hpp"

struct Grid
{
    std::size_t height = 20;
    std::size_t width = 20; 
    std::vector<std::vector<Case>> grid;
    Grid(std::size_t height, std::size_t width);
    ~Grid();
};
