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

public:
    //predicat
    bool inLife() const { return _lifePoint > 0; }
    bool haveSugar() const { return _sugar > 0; }
    bool research() const { return not(haveSugar()); }
    bool backHome() const { return haveSugar(); }

    //fonction qui décrit une action de la fourmie
    void takeSugar();
    int dropSugar();
    void move(int x, int y);
    void go_to(Coord &coord) { _pos = coord; }
    void fight(Ant other);
    void takeSugar(int sugar) { _sugar += sugar; }

    //getter
    unsigned int getColony() { return _colony; }
    Coord &getCoord() { return _pos; }
    int getNumber() const { return _number; }
    int getLifePoint() const { return _lifePoint; }
    int getSugar() const { return _sugar; }
    int getEnergy() const { return _energy; }

    //constructeur
    Ant(int number, Coord pos, unsigned int colony);
};