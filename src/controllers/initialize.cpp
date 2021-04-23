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
    Coord base;
    if (_data.numberOfColony * 2 < _data.width)
        base = Coord(coef * colony,
                     coef * (colony + 1) - 1,
                     0,
                     _data.height - 2);
    else
        base = Coord(0,
                     coef * colony,
                     _data.width - 2,
                     coef * (colony + 1) - 1);

    std::cout << "(" << base[0] << ", " << base[1] << ") ";
    _data.colonies[colony].nest.insert(_data.colonies[colony].nest.end(),
                                       {});

    for (size_t i = base[1]; i <= base[1] + 1; i++)
        for (size_t j = base[0]; j <= base[0] + 1; j++)
            _grid.grid[i][j].putNeast(colony);
}