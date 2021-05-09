#pragma once
#include "models/data.hpp"
#include "models/grid.hpp"
#include "views/display.hpp"

class Manager
{
private:
    Data _data;
    Grid _grid;
    Display _display;
    unsigned long _delay;

    void _initialize();
    void _getData();
    void _colonnyGeneration();
    void _nestCreation(char colony, unsigned int coef);
    void _nestPheroInit(char colony);
    void _spawnableCase(Coord const &coord, char colony);

public:
    Manager(unsigned long _delay);
    void start();
    void loop(long delay);
};
