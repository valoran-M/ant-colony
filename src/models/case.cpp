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
    unsigned int numberColony) : _coordinate(Coord(x, y)),
                                 _nestPheromone(std::vector<float>(numberColony, 0)),
                                 _sugarPheromone(std::vector<float>(numberColony, 0)),
                                 _colony(-1),
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
bool Case::_checkColony(unsigned int colony)
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
float Case::getNestPhero(unsigned int colony)
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
float Case::getSugarPhero(unsigned int colony)
{
    if (_checkColony(colony))
        return _sugarPheromone[colony];
    return 0;
}

int Case::containsSugarPhero()
{
    for (int i = 0; i < _sugarPheromone.size(); i++)
        if (_sugarPheromone[i] > 0)
            return i;
    return -1;
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
    return !containsAnt() && !containsNest() && !containsSugar();
}

/**
 * modifier _ant
 * @param std::size_t ant ant coefficient
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
void Case::putAnt(unsigned int ant, unsigned int colony)
{
    if (_checkCasePut())
    {
        _ant = ant;
        _colony = colony;
    }
}

/**
 * modifier _sugar
 * @param std::size_t sugar coefficient
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
void Case::putSugar(unsigned int sugar)
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
void Case::putNeast(int colony)
{
    if (_checkCasePut())
    {
        _colony = colony;
        _nest = colony;
    }
}

/**
 * modifier _nestPheromone
 * @param std::size_t colony coefficient
 * @param std::size_t substitute
 * 
 * @author Valeran MAYTIE
 * @confidenc 5
 **/
void Case::putNestPheromone(unsigned int colony, float intensity)
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
void Case::putSugarPheromone(unsigned int colony, float intensity)
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
void Case::decreasesSugarPheromone(unsigned int colony, float amount)
{
    if (_checkColony(colony))
    {
        if (amount >= _sugarPheromone[colony])
            _sugarPheromone[colony] = 0;
        else
            _sugarPheromone[colony] -= amount;
    }
}

void Case::reset()
{
    _colony = -1;
    _ant = -1;
    _nest = -1;
    _sugar = -1;
    for (int x = 0; x < _nestPheromone.size(); x++)
        _nestPheromone[x] = 0;

    for (int x = 0; x < _sugarPheromone.size(); x++)
        _sugarPheromone[x] = 0;
}