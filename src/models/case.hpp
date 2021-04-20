#pragma once

#include <vector>

class Case
{
private:
    /*
    pointeur vers les type abstrait
    Ant *_ant;
    Nest *_nest;
    Sugar *_sugar;
    */
    std::vector<std::size_t> _pheromoneNest;
    std::size_t _pheromoneSugar;

public:
    bool containsSugar();
    bool containsNest();
    bool containsAnt();
    bool isEmpty();
    // bool isOnTrack(colonie)

    void changePheromoneNest(std::size_t intensity, std::size_t colony);
    std::size_t getPheromoneNest(std::size_t colony);

    void changePheromeSugar(std::size_t intensity);
    std::size_t getPheromoneSugar(std::size_t colony);

    

    Case();
    ~Case();
};
