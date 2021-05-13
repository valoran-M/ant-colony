#include "controllers/manager.hpp"
#include "controllers/random.hpp"
#include "models/ant.hpp"
#include <iostream>

void Manager::_antManger(unsigned int colony, unsigned int ant)
{
    Ant &antEntity = _data.colonies[colony].ants[ant];
    Coord neigbourEntity;
    if (_antNeigbour(antEntity, neigbourEntity))
        _kill(antEntity,
              _grid.getCase(neigbourEntity).getColony(),
              _grid.getCase(neigbourEntity).getAnt());
    else if (_sugarNeigbour(antEntity, neigbourEntity) &&
             antEntity.getSugar() == 0)
        _getSugar(colony, ant, neigbourEntity);
    else if (_nestNeigbour(antEntity) &&
             antEntity.getSugar() != 0)
        _putSugar(colony, ant);
    else if (antEntity.haveSugar())
        _backNeast(colony, ant);
    else
        _randomMove(colony, ant);
}

void Manager::_moveAnt(unsigned int colony,
                       unsigned int ant,
                       Coord &newCase)
{
    Ant &antEntity = _data.colonies[colony].ants[ant];
    _grid.getCase(antEntity.getCoord()).removeAnt();
    _grid.getCase(newCase).putAnt(ant, colony);
    _display.setCell(antEntity.getCoord());
    _display.setCell(newCase);
    antEntity.go_to(newCase);
}

void Manager::_kill(Ant &antKiller,
                    unsigned int colonyDead,
                    unsigned int antDead)
{
    antKiller.takeSugar(_dead(colonyDead, antDead));
}

int Manager::_dead(unsigned int colonyDead, unsigned int antDead)
{
    Coord &deadAntCoord = _data.colonies[colonyDead].ants[antDead].getCoord();

    _grid.getCase(deadAntCoord)
        .removeAnt();
    _display.setCell(deadAntCoord);

    std::vector<Ant> &ants = _data.colonies[colonyDead].ants;
    int sugar = ants[antDead].getSugar();
    ants.erase(ants.begin() + antDead);
    return sugar;
}

void Manager::_getSugar(unsigned int colony, unsigned int ant, Coord &sugar)
{
    _data.colonies[colony].ants[ant].takeSugar();
    _grid.getCase(sugar).decreasesSugar();
    Coord &caseAnt = _data.colonies[colony].ants[ant].getCoord();
    _grid.getCase(caseAnt).putSugarPheromone(colony, 1);
    _data.sugarPhero[colony].push_back(caseAnt);
}

void Manager::_putSugar(unsigned int colony, unsigned int ant)
{
    _data.colonies[colony].sugar +=
        _data.colonies[colony].ants[ant].getSugar();
    _data.colonies[colony].ants[ant].dropSugar();
}

void Manager::_backNeast(unsigned int colony, unsigned int ant)
{
    std::vector<Coord> neigbours =
        _data.colonies[colony].ants[ant].getCoord().getNeigbour(_data.width, _data.height);
    Ant &ant_move = _data.colonies[colony].ants[ant];
    Case &closer = _grid.getCase(neigbours[0]);
    for (std::size_t i = 1; i < neigbours.size(); i++)
    {
        Case &test = _grid.getCase(neigbours[i]);
        if (test.getNestPhero(colony) > closer.getNestPhero(colony))
            closer = test;
    }
    _grid.getCase(ant_move.getCoord()).putSugarPheromone(colony, 1.);
    _data.sugarPhero[colony].push_back(closer.getCoord());

    _moveAnt(colony, ant, closer.getCoord());
}

void Manager::_backSugar(unsigned int colony, unsigned int ant)
{
    std::vector<Coord> neigbours =
        _data.colonies[colony].ants[ant].getCoord().getNeigbour(_data.width, _data.height);
    Ant &ant_move = _data.colonies[colony].ants[ant];
    Case &path = _grid.getCase(neigbours[0]);
    for (std::size_t i = 1; i < neigbours.size(); i++)
    {
        Case &test = _grid.getCase(neigbours[i]);
        if (path.getSugarPhero(colony) > 0)
            path = test;
    }

    _moveAnt(colony, ant, path.getCoord());
}

void Manager::_randomMove(unsigned int colony, unsigned int ant)
{
    std::vector<Coord> neigbours =
        _data.colonies[colony].ants[ant].getCoord().getNeigbour(
            _data.width, _data.height);
    std::vector<Coord> good;
    for (unsigned int i = 0; i < neigbours.size(); i++)
        if (_grid.getCase(neigbours[i]).isEmpty())
            good.push_back(neigbours[i]);
    if (good.size() > 0)
    {
        unsigned int rand = random_index(0, good.size() - 1);
        _moveAnt(colony, ant, good[rand]);
    }
}