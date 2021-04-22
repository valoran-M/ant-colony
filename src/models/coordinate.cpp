#include <stdexcept>

#include "models/coordinate.hpp"

Coord::Coord(std::size_t x, std::size_t y) : _x(x),
                                             _y(y)
{
}

std::size_t &Coord::operator[](unsigned i)
{
    if (i == 0)
        return _x;
    else if (i == 1)
        return _y;
    else
        throw std::invalid_argument("The coordinates are in 2 dimension");
}

bool Coord::operator==(Coord const &other) const
{
    return _x == other.getX() && _y == other.getY();
}

bool Coord::operator!=(Coord const &other) const
{
    return _x != other.getX() || _y != other.getY();
}