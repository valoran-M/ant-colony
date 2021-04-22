#include "models/ant.hpp"
#include "models/coordinate.hpp"


//constructeur
Ant::Ant(
    int number,
    Coord pos) : _number(number),
                 _lifePoint(10),
                 _sugar(0),
                 _pos(pos)
{
}


//getter
Coord Ant::getCoord() const
{
    return _pos;
}


int Ant::getNumber() const
{
    return _number;
}

//Déplace la fourmie d'un vecteur crée par le couple d'entier x , y
//On verifie seulement que la case vers la qu'elle elle se déplace est valide
void Ant::move(int x, int y)
{
    _pos[0] += x;
    _pos[1] += y;
}