#include "controllers/manager.hpp"
#include "controllers/random.hpp"
#include "models/ant.hpp"

void Manager::_antManger(unsigned int colony, unsigned int ant)
{
    Ant &antEntity = _data.colonies[colony].ants[ant];
    if (!antEntity.inLife())
        return;
    else if (antEntity.getSugar() != 0)
        _backNeast(antEntity);
    else
        _randomMove(antEntity);
}

void Manager::_moveAnt(Ant &antEntity,
                       Coord &newCase)
{
    _grid.getCase(antEntity.getCoord()).removeAnt();
    _grid.getCase(newCase).putAnt(antEntity.getNumber(),
                                  antEntity.getColony());
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
    Case closer;
    float nestPheroMax = 0;
    for (Coord &neigbour : neigbours)
    {
        if (_grid.getCase(neigbour).isEmpty() && _grid.getCase(neigbour).getNestPhero(antEntity.getColony()) > nestPheroMax)
        {
            closer = _grid.getCase(neigbour);
            nestPheroMax = _grid.getCase(neigbour).getNestPhero(antEntity.getColony());
        }
    }
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