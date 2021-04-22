#include "controllers/manager.hpp"
#include "models/grid.hpp"
#include "models/coordinate.hpp"
#include <iostream>

Manager::Manager() : rd(),
                     gen(rd())
{
}

void Manager::start()
{
    _initialize();
}

/**
 * return random number un index
 * @param std::size_t  min
 * @param std::size_t max
 * 
 * @return std::size_t random number
 * 
 * @author Valeran MAYHTIE
 * @confidence 2
 **/
std::size_t Manager::random_index(std::size_t lower, std::size_t higher)
{
    std::uniform_int_distribution<std::size_t> dist(lower, higher);
    return dist(gen);
}