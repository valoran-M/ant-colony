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

    //fonctions internes
    Colony(char nom);
    void antBirth(Coord coord);
    void addAnt(Coord coord) { ants.push_back(Ant(ants.size(), coord)); }
    int getNbAnt() const { return ants.size(); }
    void addNest(Coord coord);
    void removeNest(Coord coord);
};