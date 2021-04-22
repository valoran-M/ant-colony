#pragma once
#include <cstddef>

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
    Coord(std::size_t x, std::size_t y);
};