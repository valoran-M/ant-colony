#pragma once

#include <cstddef>
#include <vector>
#include <random>

class Coord
{
private:
    std::size_t _x;
    std::size_t _y;

public:
    std::size_t &operator[](unsigned i);
    std::size_t getX() const { return _x; }
    std::size_t getY() const { return _y; }
    bool operator==(Coord const &other) const;
    bool operator!=(Coord const &other) const;
    std::vector<Coord> getNeigbour(std::size_t xMax, std::size_t yMax) const;
    Coord() {}
    Coord(std::size_t x, std::size_t y);
    Coord(std::size_t xMin,
          std::size_t xMax,
          std::size_t yMin,
          std::size_t yMax);
};