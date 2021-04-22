#include "models/case.hpp"
#include <stdexcept>
#include <vector>

/**
 * to initialize case
 * @param std::size_t x coordinate
 * @param std::size_t y coordinate
 * @param std::size_t numberColony explicit :)
 * 
 * @author Valeran MAYTIE
 * @confidence 5
 **/
Case::Case(
    std::size_t x,
    std::size_t y,
    std::size_t numberColony) : _coordinate(Coord(x, y)),
                                _nestPheromone(std::vector<std::size_t>(numberColony, 0)),
                                _sugarPheromone(std::vector<std::size_t>(numberColony, 0)),
                                _ant(-1),
                                _nest(-1),
                                _sugar(-1)
{
}

/**
 * check case for put an entity
 *
 * @return bool true if is possible to put an entity
 * 
 * @author Valeran MAYTIE
 * @confidence 2
 **/
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

/**
 * Check if colony is valid
 * @param std::size_t colony coeficient
 * 
 * @return bool true if it valid
 * @confidence 2 
 **/
bool Case::_checkColony(std::size_t colony)
{
    if (colony > _nestPheromone.size())
        throw std::invalid_argument("colony is to big");
    return true;
}

/**
 * getter for _nestPheromone
 * @param std::size_t coefficient of colony
 * 
 * @return std::size_t phermone coefficient
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
std::size_t Case::getNestPhero(std::size_t colony)
{
    if (_checkColony(colony))
        return _nestPheromone[colony];
    return 0;
}

/**
 * getter for _sugarPheromone
 * @param std::size_t coefficient of colony
 * 
 * @return std::size_t phermone coefficient
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
std::size_t Case::getSugarPhero(std::size_t colony)
{
    if (_checkColony(colony))
        return _sugarPheromone[colony];
    return 0;
}

/**
 * prdicat if case is empty
 * 
 * @return bool true if case is empty
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
bool Case::isEmpty()
{
    return !(containsAnt() || containsNest() || containsSugar());
}

/**
 * modifier _ant
 * @param std::size_t ant ant coefficient
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
void Case::putAnt(std::size_t ant)
{
    if (_checkCasePut())
        _ant = ant;
}

/**
 * modifier _sugar
 * @param std::size_t sugar coefficient
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
void Case::putSugar(std::size_t sugar)
{
    if (_checkCasePut())
        _sugar = sugar;
}

/**
 * modifier _nest
 * @param std::size_t neast coefficient
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
void Case::putNeast(std::size_t neats)
{
    if (_checkCasePut())
        _nest = neats;
}

/**
 * modifier _nestPheromone
 * @param std::size_t colony coefficient
 * @param std::size_t substitute
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
void Case::putNestPheromone(std::size_t colony, std::size_t intensity)
{
    if (_checkColony(colony))
        _nestPheromone[colony] = intensity;
}

/**
 * modifier _sugarPheromone
 * @param std::size_t colony coefficient
 * @param std::size_t substitute
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
void Case::putSugarPheromone(std::size_t colony, std::size_t intensity)
{
    if (_checkColony(colony))
        _sugarPheromone[colony] = intensity;
}

/**
 * decreases the amount of sugar pheromone
 * @param std::size_t colony coefficient
 * @param std::size_t decrease amount
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
void Case::decreasesSugarPheromone(std::size_t colony, std::size_t amount)
{
    if (_checkColony(colony))
    {
        if (amount >= _sugarPheromone[colony])
            _sugarPheromone[colony] = 0;
        else
            _sugarPheromone[colony] -= amount;
    }
}