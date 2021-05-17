#include "models/colony.hpp"
#include "models/ant.hpp"
#include "models/grid.hpp"
#include "models/case.hpp"
#include <vector>

//Constructeur
Colony::Colony(Coord base, char nom) : base(base),
                                       team(nom),
                                       sugar(0)
{
}

void Colony::addNest(Coord coord)
{
    nest.push_back(coord);
}

void Colony::removeNest(Coord &coord)
{
    for (size_t i = 0; i < nest.size(); i++)
        if (nest[i] == coord)
            nest.erase(nest.begin() + i);
}