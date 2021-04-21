#pragma once
#include <cstddef>

class Coord
{
private:
    std::size_t _x;
    std::size_t _y;

public:
    int &operator[](unsigned i);
    bool operator==(Coord const & other);
    bool operator!=(Coord const & other);
    Coord(std::size_t x, std::size_t y);
};