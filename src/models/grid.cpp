#include "models/grid.hpp"
#include <iostream>

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

Case &Grid::getCase(Coord const &coord)
{
    return grid[coord.getX()][coord.getY()];
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
    for (size_t x = 0; x < xMax; x++)
    {
        grid[x] = std::vector<Case>(yMax);
        for (size_t y = 0; y < yMax; y++)
            grid[x][y] = Case(x, y, numberOfColony);
    }
    return true;
}

void Grid::reset()
{
    for (int x = 0; x < height; x++)
        for(int y = 0; y < width; y++)
            grid[y][x].reset();
}