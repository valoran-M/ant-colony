#include <stdexcept>

#include "models/grid.hpp"

Grid::Grid(std::size_t height,
           std::size_t width,
           std::size_t numberColony) : width(width),
                                       height(height)
{
    if (numberColony > 6)
        throw std::invalid_argument("To much clolony");
}