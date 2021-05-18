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
    void addNest(Coord coord);
    void removeNest(Coord &coord);
    int getNbAnt() const;
    int getNbAntDead();
    int getNbAntInLife();
};