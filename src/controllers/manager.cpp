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
    std::size_t colony, width, height;
    std::vector<std::array<Coord, 4>> nests;
    do
    {
        std::cout << "Shape of grid : ";
        std::cin >> width;
        std::cin >> height;
    } while ((width < 20 || width > 100) ||
             (height < 20 || height > 100));
    do
    {
        std::cout << "Number of colony : ";
        std::cin >> colony;
    } while (colony > 6);
    for (size_t i = 0; i < colony; i++)
    {
        std::size_t x = random_index(0, width - 1);
        std::size_t y = random_index(0, height - 1);
        nests.push_back(std::array<Coord, 4>{
            Coord(x, y),
            Coord(x + 1, y),
            Coord(x, y + 1),
            Coord(x + 1, y + 1)});
    }

    _grid.intialise(width, height, colony);
}

std::size_t Manager::random_index(std::size_t lower, std::size_t higher)
{
    std::uniform_int_distribution<std::size_t> dist(lower, higher);
    return dist(gen);
}