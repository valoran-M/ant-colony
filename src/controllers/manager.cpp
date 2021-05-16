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
            _display.updataCell(_data.sugarPhero[colony][phero]);
        }
}

bool Manager::_antNeigbour(Ant &ant, Coord &neigbour)
{
    std::vector<Coord> neigbours =
        ant.getCoord().getNeigbour(
            _data.width, _data.width);
    for (Coord coord : neigbours)
        if (_grid.getCase(coord).containsAnt() &&
            _grid.getCase(coord).getColony() != ant.getColony())
        {
            neigbour = coord;
            return true;
        }
    return false;
}

bool Manager::_sugarNeigbour(Ant &ant, Coord &neigbour)
{
    std::vector<Coord> neigbours =
        ant.getCoord().getNeigbour(
            _data.width, _data.width);
    for (Coord coord : neigbours)
        if (_grid.getCase(coord).containsSugar())
        {
            neigbour = coord;
            return true;
        }
    return false;
}

bool Manager::_nestNeigbour(Ant &ant)
{
    std::vector<Coord> neigbours =
        ant.getCoord().getNeigbour(
            _data.width, _data.width);
    for (Coord coord : neigbours)
        if (_grid.getCase(coord).containsNest() &&
            _grid.getCase(coord).getColony() == ant.getColony())
            return true;
    return false;
}

bool Manager::_sugarPheroNeigbour(Ant &ant, Coord &niegbour)
{
    std::vector<Coord> neigbours =
        ant.getCoord().getNeigbour(
            _data.width, _data.width);
    float min = 2;
    for (Coord coord : neigbours)
        if (_grid.getCase(coord).getSugarPhero(ant.getColony()) > min &&
            _grid.getCase(coord).isEmpty())
        {
            min = _grid.getCase(coord).getSugarPhero(ant.getColony());
            niegbour = coord;
        }
    return min < 2;
}