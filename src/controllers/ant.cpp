#include "controllers/manager.hpp"
#include "controllers/random.hpp"
#include "models/ant.hpp"
#include <iostream>

void Manager::_antManger(unsigned int colony, unsigned int ant)
{
    Ant &antEntity = _data.colonies[colony].ants[ant];
    if (!antEntity.inLife())
        return;
    Coord neigbourEntity;
    if (_antNeigbour(antEntity, neigbourEntity))
        _kill(antEntity,
              _grid.getCase(neigbourEntity).getColony(),
              _grid.getCase(neigbourEntity).getAnt());
    else if (antEntity.haveSugar())
        _backNeast(antEntity);
    else if (_sugarNeigbour(antEntity, neigbourEntity) &&
             antEntity.getSugar() == 0)
        _getSugar(antEntity, neigbourEntity);
    else if (_nestNeigbour(antEntity) &&
             antEntity.getSugar() != 0)
        _putSugar(antEntity);
    else if (_sugarPheroNeigbour(antEntity, neigbourEntity) && _grid.getCase(neigbourEntity).isEmpty())
        _moveAnt(antEntity, neigbourEntity);
    else
        _randomMove(antEntity);
}

void Manager::_moveAnt(Ant &antEntity,
                       Coord &newCase)
{
    _grid.getCase(antEntity.getCoord()).removeAnt();
    _grid.getCase(newCase).putAnt(antEntity.getNumber(),
                                  antEntity.getColony());
    _display.updataCell(antEntity.getCoord());
    _display.updataCell(newCase);
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
    _display.updataCell(deadAntCoord);

    std::vector<Ant> &ants = _data.colonies[colonyDead].ants;
    int sugar = ants[antDead].getSugar();
    ants[antDead].kill();
    return sugar;
}

void Manager::_getSugar(Ant &antEntity, Coord &sugar)
{
    antEntity.takeSugar();
    _grid.getCase(sugar).decreasesSugar();
    Coord &caseAnt = antEntity.getCoord();
    _grid.getCase(caseAnt).putSugarPheromone(antEntity.getColony(), 1);
    _data.sugarPhero[antEntity.getColony()].push_back(caseAnt);
}

void Manager::_putSugar(Ant &antEntity)
{
    _data.colonies[antEntity.getColony()].sugar +=
        antEntity.getSugar();
    antEntity.dropSugar();
}

void Manager::_backNeast(Ant &antEntity)
{
    std::vector<Coord> neigbours =
        antEntity.getCoord().getNeigbour(_data.width, _data.height);
    Case &closer = _grid.getCase(neigbours[0]);
    for (std::size_t i = 1; i < neigbours.size(); i++)
    {
        Case &test = _grid.getCase(neigbours[i]);
        if (test.getNestPhero(antEntity.getColony()) >= closer.getNestPhero(antEntity.getColony()) && test.isEmpty())
            closer = test;
    }
    if (!closer.isEmpty())
        return;
    _grid.getCase(antEntity.getCoord()).putSugarPheromone(antEntity.getColony(), 1.);
    _data.sugarPhero[antEntity.getColony()].push_back(closer.getCoord());

    _moveAnt(antEntity, closer.getCoord());
}

void Manager::_randomMove(Ant &antEntity)
{
    std::vector<Coord> neigbours =
        antEntity.getCoord().getNeigbour(
            _data.width, _data.height);
    std::vector<Coord> good;
    for (unsigned int i = 0; i < neigbours.size(); i++)
        if (_grid.getCase(neigbours[i]).isEmpty())
            good.push_back(neigbours[i]);
    if (good.size() > 0)
    {
        unsigned int rand = random_index(0, good.size() - 1);
        _moveAnt(antEntity, good[rand]);
    }
}