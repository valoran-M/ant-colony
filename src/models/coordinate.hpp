#pragma once

#include <vector>
#include <ostream>

class Coord
{
private:
    int _x;
    int _y;

public:
    /**
     * operator[]
     * 
     * @param unsigned coord x or y
     * 
     * @return int& 
     * 
     * @confidence 4
     **/
    int &operator[](unsigned i);

    /**
     * getter for x
     * 
     * @return int x
     * 
     * @confidence 4
     **/
    int getX() const { return _x; }

    /**
     * getter for y
     * 
     * @return int y
     * 
     * @confidence 4
     **/
    int getY() const { return _y; }

    /**
     * operator==
     * 
     * @param Coord& other
     * 
     * @return bool true if equal
     * 
     * @confidence 4
     **/
    bool operator==(Coord const &other) const;

    /**
     * operator!=
     * 
     * @param Coord& other
     * 
     * @return bool true if not equal
     * 
     * @confidence 4
     **/
    bool operator!=(Coord const &other) const;

    /**
     * get neigbour coordinate
     * 
     * @param int xMax
     * @param int yMax
     * 
     * @return std::vector<Coord>
     * 
     * @confidence 4
     **/
    std::vector<Coord> getNeigbour(int xMax, int yMax) const;

    /**
     * check if coord is in table
     * 
     * @param std::vector<Coord>& tab
     * 
     * @return bool if coord is int tab
     * 
     * @confidence 4
     **/
    bool isIn(std::vector<Coord> &tab) const;

    /**
     * constructor
     * 
     * @confidence 4
     **/
    Coord() {}

    /**
     * constructor
     * 
     * @param int x
     * @param int y
     * 
     * @confidence 4
     **/
    Coord(int x, int y);

    /**
     * constructor random coord
     * 
     * @param int xMin
     * @param int xMax
     * @param int yMin
     * @param int yMax
     * 
     * @confidence 4
     **/
    Coord(int xMin,
          int xMax,
          int yMin,
          int yMax);
};

/**
 * display opertor
 * 
 * @param std::ostream& out
 * @param Coord cont coord
 * 
 * @return std::ostream
 * 
 * @confidence 4
 **/
std::ostream &operator<<(std::ostream &out, Coord const coord);

/**
 * operator-
 * 
 * @param Coord const & coord1
 * @param Coord const & coord2
 * 
 * @return Coord
 * 
 * @confidence 4
 **/
Coord operator-(Coord const &coord1, Coord const &coord2);
