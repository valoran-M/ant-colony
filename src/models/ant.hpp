#pragma once

#include "models/coordinate.hpp"

class Ant
{
private:
    unsigned int _colony;
    int _number;
    int _sugar;
    int _lifePoint;
    int _energy;
    Coord _pos;
    Coord _rotation;

public:

    /**
     * ant is life ?
     * 
     * @return bool if is in life
     *  
     * @confidence 4
     **/
    bool inLife() const { return _lifePoint > 0; }

    /**
     * ant hase sugar ?
     * 
     * @return bool if ant add sugar
     *  
     * @confidence 4
     **/
    bool haveSugar() const { return _sugar > 0; }

    /**
     * research ?
     * 
     * @return bool if annt sherch sugar
     *  
     * @confidence 4
     **/
    bool research() const { return not(haveSugar()); }

    /**
     * back to home ?
     * 
     * @return bool if ant back to home
     *  
     * @confidence 4
     **/
    bool backHome() const { return haveSugar(); }

    /**
     * take sugar
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void takeSugar();

    /**
     * drop sugar
     * 
     * @return int number of sugar
     *  
     * @confidence 4
     **/
    int dropSugar();

    /**
     * vector move
     * 
     * @param int x 
     * @param int y
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void move(int x, int y);
    
    /**
     * got to coord
     * 
     * @param Coord&
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void go_to(Coord &coord) { _pos = coord; }

    /**
     * take sugar
     * 
     * @param int
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void takeSugar(int sugar) { _sugar += sugar; }

    /**
     * kill ant
     * 
     * @return void
     *  
     * @confidence 4
     **/
    void kill() { _lifePoint = 0; }

    /**
     * get colony
     * 
     * @return usnigned int colony
     *  
     * @confidence 4
     **/
    unsigned int getColony() { return _colony; }

    /**
     * get coord
     * 
     * @return Coord&
     *  
     * @confidence 4
     **/
    Coord &getCoord() { return _pos; }

    /**
     * get number
     * 
     * @return int
     *  
     * @confidence 4
     **/
    int getNumber() const { return _number; }

    /**
     * get life point
     * 
     * @return int
     *  
     * @confidence 4
     **/
    int getLifePoint() const { return _lifePoint; }

    /**
     * get sugar
     * 
     * @return int
     *  
     * @confidence 4
     **/
    int getSugar() const { return _sugar; }

    /**
     * get energy
     * 
     * @return int
     *  
     * @confidence 4
     **/
    int getEnergy() const { return _energy; }

    /**
     * get otation
     * 
     * @return Coord&
     *  
     * @confidence 4
     **/
    Coord &getRotation() { return _rotation; }

    /**
     * constructor
     * 
     * @param int number
     * @param Coord pos
     * @param unsigned int colony
     * @param Coord roatation
     *  
     * @confidence 4
     **/
    Ant(int number, Coord pos, unsigned int colony, Coord rotation);
};