#include "controllers/manager.hpp"
#include "models/colony.hpp"
#include "models/grid.hpp"
#include <iostream>
#include <ctime>

void Manager::_initialize()
{
    std::srand(std::time(nullptr));
    _getData();
    _grid.initilize(_data.width, _data.height, _data.numberOfColony);
    _colonnyGeneration();
    std::cout << "-------------------------------" << std::endl
              << "Nest Pheromone initialization : " << std::endl
              << "-------------------------------";
    for (unsigned int colony = 0; colony < _data.numberOfColony; colony++)
    {
        std::cout << std::endl
                  << "Colony " << colony << ": ";
        //_nestPheroInit(colony);
    }
    std::cout << std::endl;
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

    do
    {
        std::cout << "size of case (max = 30) : ";
        std::cin >> _data.caseSize;
    } while (_data.caseSize >= 30);

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
    std::cout << std::endl;
}

void Manager::_nestCreation(char colony, unsigned int coef)
{
    Coord base;
    if (_data.numberOfColony * 2 < _data.width)
        base = Coord(coef * colony, coef * (colony + 1) - 1,
                     0, _data.height - 2);
    else
        base = Coord(0, coef * colony,
                     _data.width - 2, coef * (colony + 1) - 1);

    std::cout << base << " ";
    _data.colonies[colony].nest.insert(_data.colonies[colony].nest.end(),
                                       {base,
                                        Coord(base[0] + 1, base[1]),
                                        Coord(base[0], base[1] + 1),
                                        Coord(base[0] + 1, base[1] + 1)});

    for (Coord coord : _data.colonies[colony].nest)
    {
        Case colonyCase = _grid.getCase(coord);
        colonyCase.putNeast(colony);
        colonyCase.putNestPheromone(colony, 1);
    }
}

void Manager::_nestPheroInit(unsigned int colony)
{
}