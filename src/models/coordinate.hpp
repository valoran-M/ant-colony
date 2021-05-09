#pragma once

#include <vector>
#include <ostream>

class Coord
{
private:
    unsigned int _x;
    unsigned int _y;

public:
    unsigned int &operator[](unsigned i);
    unsigned int getX() const { return _x; }
    unsigned int getY() const { return _y; }
    bool operator==(Coord const &other) const;
    bool operator!=(Coord const &other) const;
    std::vector<Coord> getNeigbour(unsigned int xMax, unsigned int yMax) const;
    Coord() {}
    Coord(unsigned int x, unsigned int y);
    Coord(unsigned int xMin,
          unsigned int xMax,
          unsigned int yMin,
          unsigned int yMax);
    bool isIn(std::vector<Coord> &tab) const;
};

std::ostream &operator<<(std::ostream &out, Coord const coord);
