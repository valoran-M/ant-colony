#include "models/case.hpp"

#include <stdexcept>
#include <vector>

Case::Case(
    std::size_t x,
    std::size_t y,
    std::size_t numberColony) : _coordinate(std::array<std::size_t, 2>{x, y}),
                                _sugarPheromone(0),
                                _ant(-1),
                                _nest(-1),
                                _sugar(-1)

{
    _nestPheromone = std::vector<std::size_t>(numberColony, 0);
}

// geter
std::array<std::size_t, 2> Case::getCoord()
{
    return _coordinate;
}

std::size_t Case::getNestPhero(std::size_t colony)
{
    if (colony >= _nestPheromone.size())
        throw std::invalid_argument("colony is to big");
    return _nestPheromone[colony];
}

std::size_t Case::getSugarPhero() { return _sugarPheromone; }
int Case::getAnt() { return _ant; }
int Case::getNest() { return _nest; }
int Case::getSugar() { return _sugar; }

//predicate
bool Case::containsAnt() { return _ant != -1; }
bool Case::containsNest() { return _nest != -1; }
bool Case::containsSugar() { return _sugar != -1; }
bool Case::isEmpty()
{
    return !(containsAnt() || containsNest() || containsSugar());
}

// modifier
bool Case::_checkCasePut()
{
    if (_ant != -1)
        throw std::invalid_argument("already a ant");
    if (_sugar != -1)
        throw std::invalid_argument("already a sugar");
    if (_nest != -1)
        throw std::invalid_argument("already a nest");
    return true;
}
void Case::putAnt(std::size_t ant)
{
    if (_checkCasePut())
        _ant = ant;
}

void Case::removeAnt() { _ant = -1; }

void Case::putSugar(std::size_t sugar)
{
    if (_checkCasePut())
        _sugar = sugar;
}
void Case::removeSugar() { _sugar = -1; }

void Case::putNeast(std::size_t neats)
{
    if (_checkCasePut())
        _nest = neats;
}

void Case::putNestPheromone(std::size_t colony, std::size_t intensity)
{
    if (colony >= _nestPheromone.size())
        throw std::invalid_argument("colony is to big");
    _nestPheromone[colony] = intensity;
}

void Case::putSugarPheromone(std::size_t intensity)
{
    _sugarPheromone = intensity;
}

void Case::decreasesSugarPheromone(std::size_t amount)
{
    if (amount >= _sugarPheromone)
        _sugarPheromone = 0;
    else
        _sugarPheromone -= amount;
}