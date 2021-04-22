#pragma once
#include "models/data.hpp"
#include "models/grid.hpp"
#include "views/display.hpp"
#include <random>

class Manager
{
private:
    Data _data;
    Grid _grid;
    Display _display;
    std::random_device rd;
    std::mt19937 gen;
    std::size_t random_index(std::size_t lower,
                             std::size_t heiger);
    void _inialise();
    void _getData();
    void _nestGeneration();

public:
    Manager();
    void start();
    void loop(long delay);
};
