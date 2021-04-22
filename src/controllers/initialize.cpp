#include "controllers/manager.hpp"
#include <iostream>

void Manager::_initialize()
{
    _getData();
    _nestGeneration();
    _grid.initilize(_data.width, _data.height);
}

void Manager::_getData()
{
    do
    {
        std::cout << "Shape of grid : ";
        std::cin >> _data.width;
        std::cin >> _data.height;
    } while ((_data.width < 20 || _data.width > 100) ||
             (_data.height < 20 || _data.height > 100));
    do
    {
        std::cout << "Number of colony : ";
        std::cin >> _data.numberOfColony;
    } while (_data.numberOfColony > 6);
}

void Manager::_nestGeneration()
{
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
}