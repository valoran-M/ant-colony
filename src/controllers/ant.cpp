#include "controllers/manager.hpp"
#include "models/ant.hpp"
#include <iostream>

void Manager::_antManger(unsigned int colony, unsigned int ant)
{
    Ant &ant_entity = _data.colonies[colony].ants[ant];
}

void Manager::_dead(unsigned int colonyDead, unsigned int antDead)
{
    Coord &deadAntCoord = _data.colonies[colonyDead].ants[antDead].getCoord();

    _grid.getCase(deadAntCoord)
        .removeAnt();
    _display.setCell(deadAntCoord);

    std::vector<Ant> &ants = _data.colonies[colonyDead].ants;
    ants.erase(ants.begin());
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
    _grid.getCase(ant_move.getCoord()).removeAnt();
    _display.setCell(ant_move.getCoord());

    ant_move.go_to(closer.getCoord());
    closer.putAnt(ant, colony);
    _display.setCell(closer.getCoord());
}