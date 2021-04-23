#include "controllers/manager.hpp"
#include "models/colony.hpp"
#include <iostream>

void Manager::_initialize()
{
    _getData();
    _grid.initilize(_data.width, _data.height, _data.numberOfColony);
    _colonnyGeneration();
}

void Manager::_getData()
{
    do
    {
        std::cout << "Shape of grid (x, y) : ";
        std::cin >> _data.width;
        std::cin >> _data.height;
    } while ((_data.width < 20 || _data.width > 1000) ||
             (_data.height < 20 || _data.height > 1000));
    unsigned int max = _data.width * _data.height / 100;
    do
    {
        std::cout << "Number of colony max(" << max << "): ";
        std::cin >> _data.numberOfColony;
    } while (_data.numberOfColony > max &&
             _data.numberOfColony > 0);
}

void Manager::_colonnyGeneration()
{
    std::cout << "nest generation : ";
    unsigned int coef;
    if (_data.numberOfColony * 2 < _data.width)
        coef = (_data.width - 1) / _data.numberOfColony;
    else
        coef = (_data.height - 1) / _data.numberOfColony;

    for (char colony = 0; colony < _data.numberOfColony; colony++)
    {
        _data.colonies.push_back(Colony(colony));
        _nestCreation(colony, coef);
    }
}

void Manager::_nestCreation(char colony, unsigned int coef)
{
    std::size_t x, y;
    if (_data.numberOfColony * 2 < _data.width)
    {
        x = random_index(coef * colony, coef * (colony + 1) - 1);
        y = random_index(0, _data.height - 2);
    }
    else
    {
        x = random_index(0, _data.width - 2);
        y = random_index(coef * colony, coef * (colony + 1) - 1);
    }
    std::cout << "(" << x << ", " << y << ") ";
    _data.colonies[colony].nest.insert(_data.colonies[colony].nest.end(),
                                       {Coord(x, y),
                                        Coord(x + 1, y),
                                        Coord(x, y + 1),
                                        Coord(x + 1, y + 1)});

    for (size_t i = y; i <= y + 1; i++)
        for (size_t j = x; j <= x + 1; j++)
            _grid.grid[i][j].putNeast(colony);
}