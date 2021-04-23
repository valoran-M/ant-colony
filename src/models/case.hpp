#pragma once

#include "models/coordinate.hpp"
#include <vector>
#include <array>

class Case
{
private:
    Coord _coordinate;
    std::vector<float> _nestPheromone;
    std::vector<float> _sugarPheromone;
    int _ant;
    int _nest;
    int _sugar;

    bool _checkCasePut();
    bool _checkColony(std::size_t colony);

public:
    // getter
    Coord getCoord() { return _coordinate; }
    float getNestPhero(unsigned int colony);
    float getSugarPhero(unsigned int colony);
    int getAnt() { return _ant; }
    int getNest() { return _nest; }
    int getSugar() { return _sugar; }

    // predicate
    bool containsAnt() { return _ant != -1; }
    bool containsNest() { return _nest != -1; }
    bool containsSugar() { return _sugar != -1; }
    bool isEmpty();

    // modifier
    void removeAnt() { _ant = -1; }
    void removeSugar() { _sugar = -1; }
    void putAnt(std::size_t ant);
    void putSugar(std::size_t sugar);
    void putNeast(int colony);
    void putNestPheromone(unsigned int colony, float intensity);
    void putSugarPheromone(unsigned int colony, float intensity);
    void decreasesSugarPheromone(unsigned int colony, float amount);

    // constructor
    Case() {}
    Case(std::size_t x, std::size_t y, unsigned int numberColony);
};
