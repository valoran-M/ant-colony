#pragma once

#include "models/colony.hpp"
#include "models/grid.hpp"

struct Data
{
    enum State
    {
        menu = 0,
        running = 1,
        paused = 2
    };

    State state;
    std::vector<Colony> colonies;
    std::vector<std::vector<Coord>> sugarPhero;

    Coord gridDim;
    unsigned int lap;
    unsigned int width;
    unsigned int height;
    unsigned int numberOfColony;
    unsigned int caseSize;
    unsigned int sugar;
    unsigned int sugarCount;
    float speed;
    float decrease;

    /**
     * add lap
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void addLap() { lap++; }

    /**
     * reset data
     * 
     * @return int
     *  
     * @confidence 4
     **/
    void reset();

    /**
     * constructor
     *  
     * @confidence 4
     **/
    Data();

    /**
     * constructor
     * 
     * @param usnigned int colony
     * @param unsigned int sugar
     * @param int cell dimm
     * @param grid dim
     *  
     * @confidence 4
     **/
    Data(unsigned int colony,
         unsigned int sugar,
         int cellDim,
         Coord gridDim);
};
