#pragma once

struct Coord
{
    int x;
    int y;
};


class Ant
{
private:
    int _number;
    int _sugar; //surment un pointeur plutard
    int _lifePoint;
    // int energy;          
    Coord _pos;

public:
    bool inLife() const;
    bool haveSugar() const;
    bool research() const;
    bool backHome() const;
    void takeSugar();
    void dropSugar();
    void move(Coord _pos);
    Coord getCoord() const;
    int getNumber() const;
    Ant(int number, Coord pos);
};