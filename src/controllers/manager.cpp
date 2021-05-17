#include "controllers/manager.hpp"
#include "models/grid.hpp"
#include "models/coordinate.hpp"
#include <iostream>

Manager::Manager(unsigned long delay,
                 bool manual,
                 unsigned int colony,
                 unsigned int sugar,
                 int cellDim,
                 Coord gridDim) : _delay(delay),
                                  _manual(manual),
                                  _data(colony, sugar, cellDim, gridDim)
{
    _getData();
}

void Manager::_reset()
{
    _data.reset();
    _grid.reset();

    _initialize();
    _display.setGird();
}

void Manager::_putSugarPhero(Ant &antEntity)
{
    _data.sugarPhero[antEntity.getColony()]
        .push_back(antEntity.getCoord());
    _grid.getCase(antEntity.getCoord())
        .putSugarPheromone(antEntity.getColony(), 1.);
}

void Manager::_decreaseSugarPhero()
{
    for (std::size_t colony = 0; colony < _data.numberOfColony; colony++)
        for (std::size_t phero = 0;
             phero < _data.sugarPhero[colony].size();
             phero++)
        {
            _grid.getCase(_data.sugarPhero[colony][phero])
                .decreasesSugarPheromone(colony, _data.decrease);
            _display.updataCell(_data.sugarPhero[colony][phero]);
            if (_grid.getCase(_data.sugarPhero[colony][phero])
                    .getSugarPhero(colony) <= 0)
            {
                _data.sugarPhero[colony].erase(
                    _data.sugarPhero[colony].begin() + phero);
                phero--;
            }
        }
}

void Manager::_cleanAnt()
{
    for (std::size_t colony = 0; colony < _data.numberOfColony; colony++)
        for (std::size_t ant = 0;
             ant < _data.colonies[colony].ants.size();
             ant++)
        {
            if (!_data.colonies[colony].ants[ant].inLife())
                _data.colonies[colony].ants.erase(
                    _data.colonies[colony].ants.begin() + ant);
        }
}