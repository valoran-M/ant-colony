#pragma once

#include "models/ant.hpp"
#include "models/coordinate.hpp"
#include <vector>

struct Colony
{

    //variables
    char team;
    std::size_t sugar;
    std::vector<Ant> ants;
    std::vector<Coord> nest;
    std::vector<Coord> spawnableCase;
    Coord base;

    //fonctions internes
    Colony(Coord base, char nom);
    int getNbAnt() const { return ants.size(); }
    void addNest(Coord coord);
    void removeNest(Coord &coord);
};