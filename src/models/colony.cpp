#include "models/colony.hpp"
#include "models/ant.hpp"
#include "models/grid.hpp"
#include "models/case.hpp"
#include <vector>

Colony::Colony(Coord base, char nom) : base(base),
                                       team(nom),
                                       sugar(10)
{
    nest.push_back(base);
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

int Colony::getNbAnt() const
{
    return ants.size();
}

int Colony::getNbAntInLife()
{
    int count = 0;
    for (Ant &ant : ants)
        if(ant.inLife())
            count++;
    return count;
}

int Colony::getNbAntDead()
{
    return getNbAnt() - getNbAntInLife();
}