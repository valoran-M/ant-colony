#pragma once

#include <vector>
#include <array>

class Case
{
private:
    std::array<std::size_t, 2> _coordinate;
    std::vector<std::size_t> _nestPheromone;
    std::size_t _sugarPheromone;
    int _ant;
    int _nest;
    int _sugar;

public:
    // access
    std::array<std::size_t, 2> getCoord();
    std::size_t getNestPhero(std::size_t colony);
    std::size_t getSugarPhero();
    int getAnt();
    int gatNest();
    int getSugar();

    // predicate
    bool containsAnt();
    bool containsNest();
    bool containsSugar();
    bool isEmpty();

    // phermone fonction
    void putNestPheromone(std::size_t colony, std::size_t intensity);
    void putSugarPheromone(std::size_t intensity);
    void decreasesSugarPheromone(std::size_t amount);

    Case(std::size_t x, std::size_t y, std::size_t numberColony);
};
