#pragma once

#include <vector>
#include <array>

class Case
{
private:
    std::array<std::size_t, 2> _coordinate;
    std::vector<std::size_t> _nestPheromone;
    std::vector<std::size_t> _sugarPheromone;
    int _ant;
    int _nest;
    int _sugar;

    bool _checkCasePut();
    bool _checkColony(std::size_t colony);

public:
    // getter
    std::array<std::size_t, 2> getCoord() { return _coordinate; }
    std::size_t getNestPhero(std::size_t colony);
    std::size_t getSugarPhero(std::size_t colony);
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
    void putNeast(std::size_t neats);
    void putNestPheromone(std::size_t colony, std::size_t intensity);
    void putSugarPheromone(std::size_t colony, std::size_t intensity);
    void decreasesSugarPheromone(std::size_t colony, std::size_t amount);

    // constructor
    Case(std::size_t x, std::size_t y, std::size_t numberColony);
};
