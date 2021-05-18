#include "models/ant.hpp"
#include "models/coordinate.hpp"
#include <stdexcept>

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

int Ant::dropSugar()
{
    int nbSucre = _sugar;
    _sugar = 0;
    _energy = 5;
    return nbSucre;
}

void Ant::move(int x, int y)
{
    _pos[0] += x;
    _pos[1] += y;
}