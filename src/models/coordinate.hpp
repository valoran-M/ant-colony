#pragma once

#include <vector>
#include <ostream>

class Coord
{
private:
    int _x;
    int _y;

public:
    int &operator[](unsigned i);
    int getX() const { return _x; }
    int getY() const { return _y; }
    bool operator==(Coord const &other) const;
    bool operator!=(Coord const &other) const;
    std::vector<Coord> getNeigbour(int xMax, int yMax) const;
    Coord() {}
    Coord(int x, int y);
    Coord(int xMin,
          int xMax,
          int yMin,
          int yMax);
    bool isIn(std::vector<Coord> &tab) const;
};

std::ostream &operator<<(std::ostream &out, Coord const coord);
