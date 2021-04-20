#pragma once

#include <vector>
#include <array>

class Case
{
private:
    std::array<std::size_t, 2> _coordinate;
    std::vector<std::size_t> _pheromoneNest;
    std::size_t _pheromoneSugar;
    int _ant;
    int _nest;
    int _sugar;

public:
    std::array<std::size_t, 2> coord();

    // predicate
    bool containsAnt();
    bool containsNest();
    bool containsSugar();
    bool isEmpty();

    //Phermone Fonction
    void changePheromoneNest(std::size_t intensity, std::size_t colony);
    std::size_t getPheromoneNest(std::size_t colony);

    void changePheromeSugar(std::size_t intensity);
    std::size_t getPheromoneSugar();

    Case(std::size_t x, std::size_t y, std::size_t numberColony);
};
