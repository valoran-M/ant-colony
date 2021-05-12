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
    _data.colonies[colonyDead].ants.erase(
        _data.colonies[colonyDead].ants.begin() + antDead);
    _grid.getCase(deadAntCoord).removeAnt();
    _display.setCell(deadAntCoord);
}

void Manager::_getSugar(unsigned int colony, unsigned int ant)
{
    
}