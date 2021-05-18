#pragma once

#include "models/coordinate.hpp"

class Case
{
private:
    Coord _coordinate;
    std::vector<float> _nestPheromone;
    std::vector<float> _sugarPheromone;
    int _colony;
    int _ant;
    int _nest;
    int _sugar;
    bool _barrier;

    /**
     * check case
     * 
     * @return bool true if case is valid
     *  
     * @confidence 2
     **/
    bool _checkCasePut();

    /**
     * check colony
     * 
     * @return bool true if colony is valid
     *  
     * @confidence 2
     **/
    bool _checkColony(unsigned int colony);

public:
    // getter

    /**
     * give case coord
     * 
     * @return Coord&
     *  
     * @confidence 4
     **/
    Coord &getCoord() { return _coordinate; }

    /**
     * give nest phero
     * 
     * @param unsigned int colony
     * 
     * @return flaot 
     *  
     * @confidence 4
     **/
    float getNestPhero(unsigned int colony);

    /**
     * give sugar phero
     * 
     * @param unsigned int colony
     * 
     * @return flaot 
     *  
     * @confidence 4
     **/
    float getSugarPhero(unsigned int colony);

    /**
     * give colony
     * 
     * @return int
     *  
     * @confidence 4
     **/
    int getColony() { return _colony; }

    /**
     * give ant
     * 
     * @return int
     *  
     * @confidence 4
     **/
    int getAnt() { return _ant; }

    /**
     * give nest
     * 
     * @return int
     *  
     * @confidence 4
     **/
    int getNest() { return _nest; }

    /**
     * give sugar
     * 
     * @return int
     *  
     * @confidence 4
     **/
    int getSugar() { return _sugar; }

    // predicate

    /**
     * give barrier
     * 
     * @return bool true if case contain barrier
     *  
     * @confidence 4
     **/
    bool getBarrier() { return _barrier; }

    /**
     * check if case contain ant
     * 
     * @return bool true if case contain ant
     *  
     * @confidence 4
     **/
    bool containsAnt() { return _ant != -1; }

    /**
     * check if case contain nest
     * 
     * @return bool true if case contain nest
     *  
     * @confidence 4
     **/
    bool containsNest() { return _nest != -1; }

    /**
     * check if case contain sugar
     * 
     * @return bool true if case contain sugar
     *  
     * @confidence 4
     **/
    bool containsSugar() { return _sugar != 0; }

    /**
     * check if case contain sugar Phero
     * 
     * @return int colony of sugar phero
     *  
     * @confidence 4
     **/
    int containsSugarPhero();

    /**
     * check if case is empty
     * 
     * @return bool if case is empty
     *  
     * @confidence 4
     **/
    bool isEmpty();

    // modifier

    /**
     * remove ant
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void removeAnt() { _colony = _ant = -1; }

    /**
     * remove sugar
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void removeSugar() { _sugar = 0; }
    
    /**
     * put barrier 
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void putBarrier() { _barrier = true; }

    /**
     * remove barrier
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void removeBarrier() { _barrier = false; }

    /**
     * put ant
     * 
     * @param int colony
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void putAnt(unsigned int ant, unsigned int colony);

    /**
     * remove ant
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void putSugar(unsigned int sugar);

    /**
     * put neast
     * 
     * @param int colonu
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void putNeast(int colony);

    /**
     * put nest phero
     * 
     * @param unsigned int colony
     * @param float intensity
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void putNestPheromone(unsigned int colony, float intensity);

    /**
     * put sugar phero
     * 
     * @param unsinged int colony
     * @param float intensity
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void putSugarPheromone(unsigned int colony, float intensity);

    /**
     * decreses sugar
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void decreasesSugar() { _sugar -= 1; }

    /**
     * decrese sugar phero
     * 
     * @param usngined int colony
     * @param float amount
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void decreasesSugarPheromone(unsigned int colony, float amount);

    /**
     * remove every nest phero
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void removeNestPhero();

    /**
     * remove nest phero
     * 
     * @param int colony
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void removeNestPhero(int colony);

    /**
     * basic constructor
     * 
     * @return void
     *  
     * @confidence 4
     **/
    Case() {}

    /**
     * constructor
     * 
     * @param std::size_t x
     * @param std::size_t y
     * @param unsigned int number of colony
     * 
     * @return void
     *  
     * @confidence 4
     **/
    Case(std::size_t x, std::size_t y, unsigned int numberColony);

    /**
     * constructor
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void reset();
};
