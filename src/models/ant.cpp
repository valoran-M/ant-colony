#include "models/ant.hpp"
#include "models/coordinate.hpp"
#include <stdexcept>

//constructeur
Ant::Ant(
    int number,
    Coord pos,
    unsigned int colony,
    Coord rotation) : _colony(colony),
                      _number(number),
                      _lifePoint(10),
                      _energy(5),
                      _sugar(0),
                      _pos(pos),
                      _rotation(rotation)
{
}

//permet a la fourmie de prendre un sucre en contre parti elle perd un point d'energy
void Ant::takeSugar()
{
    if (_sugar < 3)
    {
        _sugar += 1;
        _energy -= 1;
    }
    else
    {
        throw std::invalid_argument("Can't hold more sugar");
    }
}

//renvoie le nombre de sucre dont se débarasse la fourmie et enlève tous les sucres de la fourmie
int Ant::dropSugar()
{
    int nbSucre = _sugar;
    _sugar = 0;
    _energy = 5;
    return nbSucre;
}

//Déplace la fourmie d'un vecteur crée par le couple d'entier x , y
//On verifie seulement que la case vers la qu'elle elle se déplace est valide
void Ant::move(int x, int y)
{
    _pos[0] += x;
    _pos[1] += y;
}

//premisse des combats de fourmis
//Non testé pour le moment
void Ant::fight(Ant other)
{
    while (inLife() or other.inLife())
    {
        other._lifePoint -= _energy;
        _lifePoint -= other._energy;
    }
}