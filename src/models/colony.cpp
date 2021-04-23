#include "models/colony.hpp"
#include "models/ant.hpp"
#include "models/grid.hpp"
#include "models/case.hpp"
#include <vector>


//Constructeur
Colony::Colony(char nom,
               Coord posi) : team(nom),
                             sugar(100),
                             ants(std::vector<Ant>(1, Ant(0, pos[0]))),
                             nest(std::vector<Coord>(1, posi))
{
}


//Il y a volontairement une erreure dans la création de la fourmie en attendant une vrai struct coord
void Colony::newAnt()
{
    if (sugar >= 25)
    {
        sugar -= 25;
        ants.push_back(Ant(ants.size(), Coord(0,0)));
    }
}