#pragma once

#include "models/case.hpp"
#include <vector>

struct Grid
{
    unsigned int height;
    unsigned int width;
    std::vector<std::vector<Case>> grid;

    /**
     * get case
     * 
     * @param Coord cont & coord
     * 
     * @return Case&
     *  
     * @confidence 4
     **/
    Case &getCase(Coord const &coord);

    /**
     * get case
     * 
     * @param int x
     * @param int y
     * 
     * @return Case&
     *  
     * @confidence 4
     **/
    Case &getCase(int x, int y) { return grid[x][y]; }

    /**
     * reset
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void reset();

    /**
     * remove nest phero
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void removeNestPhero();

    /**
     * init grid
     * 
     * @param unsigned int xMax
     * @param unsigned int yMax
     * @param unsinged int number of colony
     * 
     * @return voi
     *  
     * @confidence 4
     **/
    void initilize(unsigned int xMax,
                   unsigned int yMax,
                   unsigned int numberOfColony);

    /**
     * constructor
     *  
     * @confidence 4
     **/
    Grid();
};
