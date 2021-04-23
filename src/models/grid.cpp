#include "models/grid.hpp"

/**
 * Constructor for grid
 * 
 * @author Valeran MAYTIE
 * @confidence  2
 **/
Grid::Grid() : height(0),
               width(0),
               grid()
{
}

/**
 * Initalise grid
 * 
 * @param std::size_t width
 * @param std::size_t heiight
 * 
 * @return bool true if initilize corect
 * 
 * @author Valeran MAYTIE
 * @confidence 2
 **/
bool Grid::initilize(unsigned int xMax,
                     unsigned int yMax,
                     unsigned int numberOfColony)
{
    width = xMax;
    height = yMax;
    grid = std::vector<std::vector<Case>>(yMax);
    for (size_t y = 0; y < yMax; y++)
    {
        grid[y] = std::vector<Case>(xMax);
        for (size_t x = 0; x < xMax; x++)
            grid[y][x] = Case(x, y, numberOfColony);
    }
    return true;
}