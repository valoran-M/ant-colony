#include "controllers/random.hpp"
#include "controllers/manager.hpp"
#include "models/colony.hpp"
#include "models/grid.hpp"
#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>

void Manager::_initialize()
{
    _data.decrease = 1 / std::sqrt(float(_data.width * _data.width + _data.height * _data.height));
    _data.decrease /= 2;
    _grid.initilize(_data.width, _data.height, _data.numberOfColony);
    _display.display_init(&_data,
                          &_grid,
                          _data.caseSize);
    _colonnyGeneration();
    _sugarCreation();
    _display.setGird();
}

void Manager::_getData()
{
    unsigned int max;
    while ((_data.width < 20 || _data.width > 1000) ||
           (_data.height < 20 || _data.height > 1000) ||
           _data.height != _data.width)
    {
        std::cout << "Shape of grid (x, y) : ";
        std::cin >> _data.width;
        std::cin >> _data.height;
    };

    while (_data.caseSize > 30)
    {
        std::cout << "size of case (max = 30) : ";
        std::cin >> _data.caseSize;
    };

    max = std::min(_data.width, _data.height) / 4;
    while (_data.numberOfColony > max ||
           _data.numberOfColony <= 0)
    {
        std::cout << "Number of colony max(" << max << "): ";
        std::cin >> _data.numberOfColony;
    };
    max = ((_data.height * _data.width) -
           (_data.numberOfColony * 16)) /
          30;
    while (_data.sugar > max)
    {
        std::cout << "Number of sugar max(" << max << "): ";
        std::cin >> _data.sugar;
    };
}

void Manager::_colonnyGeneration()
{
    std::vector<int> x_grid, y_grid;
    for (int x = 0; x < _data.width / 4; x++)
        x_grid.push_back(x);
    for (int y = 0; y < _data.height / 4; y++)
        y_grid.push_back(y);

    for (unsigned int colony = 0; colony < _data.numberOfColony; colony++)
    {
        _data.colonies.push_back(Colony(Coord(0, 0), colony));
        _data.sugarPhero.push_back(std::vector<Coord>(0));
        if (!_manual)
        {
            std::cout << "nest generation : ";
            _randomNestCreation(_data.colonies[colony], x_grid, y_grid);
        }
        else
        {
            Coord base;
            do
            {
                base = _display.getNestCreation();
            } while (!_baseTest(base));

            _nestCreation(_data.colonies[colony], base);
            _display.setGird();
        }
    }

    std::cout << std::endl
              << "-------------------------------" << std::endl
              << "Nest Pheromone initialization :" << std::endl
              << "-------------------------------" << std::endl;

    for (unsigned int colony = 0; colony < _data.numberOfColony; colony++)
        _nestPheroInit(colony);
}

void Manager::_randomNestCreation(Colony &colony,
                                  std::vector<int> &x_grid,
                                  std::vector<int> &y_grid)
{
    int random_x, random_y;
    random_x = random_index(0, x_grid.size() - 1);
    random_y = random_index(0, y_grid.size() - 1);
    Coord base(x_grid[random_x] * 4 + 1, y_grid[random_y] * 4 + 1);
    x_grid.erase(x_grid.begin() + random_x);
    y_grid.erase(y_grid.begin() + random_y);
    std::cout << base << " ";
    _nestCreation(colony, base);
}

bool Manager::_baseTest(Coord &base)
{
    if ((base[0] < 1 || base[0] > _data.width - 2) &&
        (base[1] < 1 || base[1] > _data.height - 2))
        return false;
    for (int y = base[1] - 1; y < base[1] + 3; y++)
        for (int x = base[0] - 1; x < base[0] + 3; x++)
            if (!_grid.getCase(Coord(x, y)).isEmpty())
                return false;
    return true;
}

void Manager::_nestCreation(Colony &colony, Coord base)
{
    colony.base = base;
    colony.nest.insert(colony.nest.end(),
                       {base,
                        Coord(base[0] + 1, base[1]),
                        Coord(base[0], base[1] + 1),
                        Coord(base[0] + 1, base[1] + 1)});
    for (Coord coord : colony.nest)
    {
        Case &colonyCase = _grid.getCase(coord);
        colonyCase.putNeast(colony.team);
        colonyCase.putNestPheromone(colony.team, 1);
        _spawnableCase(coord, colony.team);
    }
}

void Manager::_spawnableCase(Coord const &coord, char colony)
{
    std::vector<Coord> neigbours = coord.getNeigbour(_data.height,
                                                     _data.width);
    for (Coord const &neigbour : neigbours)
        if (!(neigbour.isIn(_data.colonies[colony].nest) ||
              neigbour.isIn(_data.colonies[colony].spawnableCase)))
        {
            _data.colonies[colony].spawnableCase.push_back(neigbour);
            _data.colonies[colony].addAnt(neigbour);
            _grid.getCase(neigbour).putAnt(
                _data.colonies[colony].ants.size() - 1,
                colony);
        }
}

void Manager::_nestPheroInit(char colony)
{
    std::vector<Coord> neig;
    int x, y, neigI, size;
    float max, maxPheroCase, casePhero;
    bool stable = false;
    size = std::min(_data.height, _data.width);
    for (y = 0; y < _data.height; y++)
        for (x = 0; x < _data.width; x++)
            _grid.getCase(y, x).removeNestPhero(colony);
    std::cout << "Colony " << int(colony) << " "
              << ":";
    while (!stable)
    {
        std::cout << "*";
        stable = true;
        for (y = 0; y < _data.height; y++)
            for (x = 0; x < _data.width; x++)
            {
                Case &p = _grid.getCase(y, x);
                if ((casePhero = p.getNestPhero(colony)) < 1)
                {
                    neig = p.getCoord().getNeigbour(_data.width,
                                                    _data.height);
                    max = _grid.getCase(neig[0]).getNestPhero(colony);
                    for (neigI = 1; neigI < neig.size(); neigI++)
                        max = std::max(max,
                                       _grid.getCase(neig[neigI]).getNestPhero(colony));

                    maxPheroCase = max - 1. / size;
                    if (maxPheroCase > casePhero &&
                        p.getNest() == -1 &&
                        !p.getBarrier() &&
                        p.getSugar() == 0)
                    {
                        p.putNestPheromone(colony, maxPheroCase);
                        stable = false;
                    }
                }
            }
    }
    std::cout << std::endl;
}

void Manager::_sugarCreation()
{
    unsigned int sugar = 0;
    Coord sugarCoord;
    while (sugar < _data.sugar)
    {
        while (!_grid.getCase(sugarCoord = Coord(random_index(0, _data.width - 1),
                                                 random_index(0, _data.width - 1)))
                    .isEmpty())
            ;
        _grid.getCase(sugarCoord).putSugar(10);
        sugar++;
    }
}
