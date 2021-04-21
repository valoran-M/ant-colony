#pragma once

struct Coord
{
    int x;
    int y;
};


class Ant
{
private:
    int number;
    char Team;
    int Sugar; //surment un pointeur plutard
    // int lifePoint;
    // int energy;          
    Coord pos;

public:
    bool inLife() const;
    bool haveSugar() const;
    bool research() const;
    bool backHome() const;
    void takeSugar();
    void dropSugar();
    void move(Coord pos);
    Coord coord() const;
};