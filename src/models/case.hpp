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
    
    bool _checkCasePut();

public:
    // access
    std::array<std::size_t, 2> getCoord();
    std::size_t getNestPhero(std::size_t colony);
    std::size_t getSugarPhero();
    int getAnt();
    int getNest();
    int getSugar();

    // predicate
    bool containsAnt();
    bool containsNest();
    bool containsSugar();
    bool isEmpty();

    // modifier
    void putAnt(std::size_t ant);
    void removeAnt();
    void putSugar(std::size_t sugar);
    void removeSugar();
    void putNeast(std::size_t neats);
    void putNestPheromone(std::size_t colony, std::size_t intensity);
    void putSugarPheromone(std::size_t intensity);
    void decreasesSugarPheromone(std::size_t amount);

    Case(std::size_t x, std::size_t y, std::size_t numberColony);
};
