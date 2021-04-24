#include "models/coordinate.hpp"
#include <stdexcept>
#include <vector>
#include <random>

/**
 * Constructor for Coor
 * @param std::size_t x
 * @param std::size_t y
 * 
 * @author Valeran MAYTIE
 * @condifence 5 
 **/
Coord::Coord(std::size_t x, std::size_t y) : _x(x),
                                             _y(y)
{
}

/**
 * random constructor Coord
 * @param std::size_t xMin
 * @param std::size_t xMax
 * @param std::size_t yMin
 * @param std::size_t yMax
 * 
 * @author Valeran MAYHTIE
 * @confidence 2
 **/
Coord::Coord(std::size_t xMin,
             std::size_t xMax,
             std::size_t yMin,
             std::size_t yMax)
{

    _x = std::rand() % (xMax - xMin) + xMin;
    _y = std::rand() % (yMax - yMin) + yMin;
}

/**
 * opetor [] for Coor
 * @param unsigned accesseur
 * 
 * @return std::size_t & adress of x or y coordinate
 * @author Valeran MAYTIE
 * @condifence 5 
 **/
std::size_t &Coord::operator[](unsigned i)
{
    if (i == 0)
        return _x;
    else if (i == 1)
        return _y;
    else
        throw std::invalid_argument("The coordinates are in 2 dimension");
}

/**
 * opetor == for Coor
 * @param Coor const & other Coor
 * 
 * @return bool true if this == other
 * @author Valeran MAYTIE
 * @condifence 5 
 **/
bool Coord::operator==(Coord const &other) const
{
    return _x == other.getX() && _y == other.getY();
}

/**
 * opetor != for Coor
 * @param Coor const & other Coor
 * 
 * @return bool true if this != other
 * @author Valeran MAYTIE
 * @condifence 5 
 **/
bool Coord::operator!=(Coord const &other) const
{
    return _x != other.getX() || _y != other.getY();
}

std::ostream &operator<<(std::ostream &out, Coord const cord)
{
    out << "(" << cord.getX() << ", " << cord.getY() << ")";
    return out;
}

/** 
 * return neigbour of Coord
 * @param std::size_t max x in table
 * @param std::size_t max y in table
 * 
 * @return std::vecotr<Coord> set of coord
 * @author Valeran MAYTIE
 * @condifence 5 
 **/
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