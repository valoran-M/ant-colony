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
    std::random_device rd;
    std::mt19937 gen;

    void _initialize();
    void _getData();
    void _colonnyGeneration();
    void _nestCreation(char colony, unsigned int coef);
    void _nestPheroInit(unsigned int colony);
    void _nestCase(Coord coord, unsigned int colony);

public:
    Manager();
    void start();
    void loop(long delay);
};
