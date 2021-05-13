#include "controllers/manager.hpp"
#include "models/grid.hpp"
#include "models/coordinate.hpp"

Manager::Manager(unsigned long delay) : _delay(delay)
{
}

void Manager::_reset()
{
    _data.reset();
    _grid.reset();

    _initialize();
    _display.setGird();
}

void Manager::_decreaseSugarPhero()
{
    for (std::size_t colony = 0; colony < _data.numberOfColony; colony++)
        for (std::size_t phero = 0;
             phero > _data.sugarPhero[colony].size();
             phero++)
        {
            _grid.getCase(_data.sugarPhero[colony][phero])
                .decreasesSugarPheromone(colony, _data.decrease);
            if (_grid.getCase(_data.sugarPhero[colony][phero])
                    .getSugarPhero(colony) == 0)
                _data.sugarPhero[colony].erase(
                    _data.sugarPhero[colony].begin() + phero);
        }
}