#pragma once

#include "models/ant.hpp"
#include <vector>


struct Colony
{

    //variables
    char team;
    std::size_t sugar;
    std::vector<Ant> ants;
    std::vector<Coord> pos;


    //fonctions internes
    Colony(char nom, Coord posi);
    void newAnt();
    int getNbAnt() const { return return ants.size(); }
};