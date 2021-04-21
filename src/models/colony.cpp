#include <vector>
#include "models/colony.hpp"
#include "models/ant.hpp"
#include "models/grid.hpp"
#include "models/case.hpp"


//full bug a réparer de toute Urgence
//Colony::Colony(char nom,
//                Coord posi) :
//                            team(nom),
//                            sugar(100),
//                            ants(std::vector<Ant>(Ant a(0,pos[0]))),
//                            pos(std::vector<Coord>(posi))
//{
    //if (grid[posi.x][posi.y] != 'None') 
    //    throwstd::invalid_argument ("La case ou l'on implémente la coloni n'est pas vide")
//}


//Il y a volontairement une erreure dans la création de la fourmie en attendant une vrai struct coord
void Colony::newAnt()
{
    if (sugar >= 25)
    {
        sugar -= 25;
        ants.push_back(Ant(std::size(ants),pos[0]));
    }
}


int Colony::getNbAnt() const
{
    return std::size(ants);
}
