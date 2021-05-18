#pragma once

#include "models/ant.hpp"
#include "models/coordinate.hpp"
#include <vector>

struct Colony
{

    char team;
    std::size_t sugar;
    std::vector<Ant> ants;
    std::vector<Coord> nest;
    std::vector<Coord> spawnableCase;
    Coord base;

    /**
     * constructor
     * 
     * @param Coord base
     * @param char nom
     * 
     * @confidence 4
     **/
    Colony(Coord base, char nom);

    /**
     * add nest
     * 
     * @param Coord base
     * 
     * @return void
     *
     * @confidence 4
     **/
    void addNest(Coord coord);

    /**
     * remove nest
     * 
     * @param Coord& base
     * 
     * @return void
     * 
     * @confidence 4
     **/
    void removeNest(Coord &coord);

    /**
     * get number of ant
     * 
     * @return int number of ant
     *
     * @confidence 4
     **/
    int getNbAnt() const;

    /**
     * get number of dead ant
     * 
     * @return int number of deand ant
     *
     * @confidence 4
     **/
    int getNbAntDead();

    /**
     * get number of dead ant
     * 
     * @return int number of deand ant
     *
     * @confidence 4
     **/
    int getNbAntInLife();
};