#include "models/colony.hpp"
#include "models/ant.hpp"
#include "models/grid.hpp"
#include "models/case.hpp"
#include <vector>

//Constructeur
Colony::Colony(char nom) : team(nom)
{
}

void Colony::addNest(Coord coord)
{
    nest.push_back(coord);
}

void Colony::removeNest(Coord coord)
{
    for (size_t i = 0; i < nest.size(); i++)
        if (nest[i] == coord)
            nest.erase(nest.begin() + i);
}

void Colony::antBirth(Coord coord)
{
    if (sugar >= 25)
    {
        sugar -= 25;
        addAnt(coord);
    }
}