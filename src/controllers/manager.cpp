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
    _inialise();
    std::size_t colony, width, height;
    std::vector<std::array<Coord, 4>> nests;
    for (size_t i = 0; i < _data.numberOfColony; i++)
    {
        std::size_t x = random_index(0, _data.width - 1);
        std::size_t y = random_index(0, _data.height - 1);
        nests.push_back(std::array<Coord, 4>{
            Coord(x, y),
            Coord(x + 1, y),
            Coord(x, y + 1),
            Coord(x + 1, y + 1)});
    }

    _grid.intialise(width, height);
}

std::size_t Manager::random_index(std::size_t lower, std::size_t higher)
{
    std::uniform_int_distribution<std::size_t> dist(lower, higher);
    return dist(gen);
}