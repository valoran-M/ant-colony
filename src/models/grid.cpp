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
bool Grid::initilize(std::size_t xMax,
                     std::size_t yMax)
{
    width = xMax;
    height = yMax;
    return true;
}