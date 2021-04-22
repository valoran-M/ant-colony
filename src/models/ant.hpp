#pragma once

#include "models/coordinate.hpp"


class Ant
{
private:
    int _number;
    int _sugar;
    int _lifePoint;
    // int energy;          
    Coord _pos;

public:
//predicat
    bool inLife() const { return _lifePoint > 1; }
    bool haveSugar() const { return _sugar > 0; }
    bool research() const { return haveSugar(); }
    bool backHome() const { return not(haveSugar()); }
//fonction qui modifie une caractéristique de la fourmie
    void takeSugar() { _sugar += 1; };
    void dropSugar() { _sugar = 0 };
    void move(int x,int y);
//getter
    Coord getCoord() const;
    int getNumber() const;
//constructeur
    Ant(int number, Coord pos);
};