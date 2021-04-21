#pragma once

#include "models/coordinate.hpp"


class Ant
{
private:
    int _number;
    int _sugar; //surment un pointeur plutard
    int _lifePoint;
    // int energy;          
    Coord _pos;

public:
//predicat
    bool inLife() const;
    bool haveSugar() const;
    bool research() const;
    bool backHome() const;
//fonction
    void takeSugar();
    void dropSugar();
    void move(Coord _pos);
//getter
    Coord getCoord() const;
    int getNumber() const;
//constructeur
    Ant(int number, Coord pos);
};