#include "models/case.hpp"

#include <vector>

Case::Case(
    std::size_t x,
    std::size_t y,
    std::size_t numberColony) : _coordinate(std::array<std::size_t, 2>{x, y}),
                                _pheromoneNest(0),
                                _pheromoneSugar(0),
                                _ant(-1),
                                _nest(-1),
                                _sugar(-1)

{
    _pheromoneNest = std::vector<std::size_t>(numberColony, 0);
}

std::array<std::size_t, 2> Case::coord()
{
    return _coordinate;
}

bool Case::containsAnt()
{
    return _ant != -1;
}

bool Case::containsNest()
{
    return _sugar != -1;
}

bool Case::containsSugar()
{
    return _sugar != -1;
}
bool Case::isEmpty()
{
    return ! (containsAnt() || containsNest() || containsSugar()); 
}

void Case::changePheromoneNest(std::size_t intensity, std::size_t colony)
{
    _pheromoneNest[colony] = intensity;
}

std::size_t Case::getPheromoneNest(std::size_t colony)
{
    return _pheromoneNest[colony];
}

void Case::changePheromeSugar(std::size_t intensity)
{
    _pheromoneSugar = intensity;
}

std::size_t Case::getPheromoneSugar()
{
    return _pheromoneSugar;
}