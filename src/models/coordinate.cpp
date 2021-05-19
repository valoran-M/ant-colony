#include "models/coordinate.hpp"
#include "controllers/random.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

Coord::Coord(int x, int y) : _x(x),
                             _y(y)
{
}

Coord::Coord(int xMin,
             int xMax,
             int yMin,
             int yMax)
{

    _x = random_index(xMin, xMax);
    _y = random_index(yMin, yMax);
}

int &Coord::operator[](unsigned i)
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

std::ostream &operator<<(std::ostream &out, Coord const cord)
{
    out << "(" << cord.getX() << ", " << cord.getY() << ")";
    return out;
}

std::vector<Coord> Coord::getNeigbour(int width, int height) const
{
    int xMin = std::max<int>(getX() - 1, 0);
    int xMax = std::min<int>(getX() + 1, width - 1);
    int yMin = std::max<int>(getY() - 1, 0);
    int yMax = std::min<int>(getY() + 1, height - 1);

    std::vector<Coord> neigbours;
    for (int y = yMin; y <= yMax; y++)
        for (int x = xMin; x <= xMax; x++)
            if (x != getX() || y != getY())
                neigbours.push_back(Coord(x, y));
    return neigbours;
}

bool Coord::isIn(std::vector<Coord> &tab) const
{
    for (Coord &coord : tab)
        if (coord == *this)
            return true;
    return false;
}

Coord operator-(Coord const &coord1, Coord const &coord2)
{
    return Coord(coord1.getX() - coord2.getX(), coord2.getY() - coord1.getY());
}