#include <stdexcept>

#include "models/grid.hpp"

Grid::Grid() : height(0),
               width(0),
               grid()
{
}

bool Grid::intialise(std::size_t xMax,
                     std::size_t yMax)
{
    width = xMax;
    height = yMax;
    return true;
}