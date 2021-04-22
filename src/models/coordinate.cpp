#include <stdexcept>
#include <vector>
#include <iostream>
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

std::vector<Coord> Coord::getNeigbour(std::size_t width, std::size_t height) const
{
    int xMin = std::max<int>(getX() - 1, 0);
    int xMax = std::min<int>(getX() + 1, width - 1);
    int yMin = std::max<int>(getY() - 1, 0);
    int yMax = std::min<int>(getY() + 1, height - 1);

    std::vector<Coord> neigbours;
    for (std::size_t y = yMin; y <= yMax; y++)
        for (std::size_t x = xMin; x <= xMax; x++)
            if (x != getX() || y != getY())
                neigbours.push_back(Coord(x, y));
    return neigbours;
}