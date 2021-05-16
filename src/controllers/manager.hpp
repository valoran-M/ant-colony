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
    bool _manual;

    // init
    void _initialize();
    void _reset();

    void _getData();
    bool _baseTest(Coord &base);
    void _colonnyGeneration();
    void _randomNestCreation(Colony &colony,
                             std::vector<int> &x_grid,
                             std::vector<int> &y_grid);
    void _nestCreation(Colony &colony, Coord base);
    void _nestPheroInit(char colony);
    void _sugarCreation();
    void _spawnableCase(Coord const &coord, char colony);

    void _eventTraitment(Display::events event);

    void _lapUpdate();

    // ant manager
    void _antManger(unsigned int colony, unsigned int ant);
    void _moveAnt(Ant &antEntity, Coord &newCase);
    void _kill(Ant &antKiller,
               unsigned int colonyDead,
               unsigned int antDead);
    int _dead(unsigned int colonyDead, unsigned int antDead);
    void _getSugar(Ant &antEntity, Coord &sugar);
    bool _putSugar(Ant &antEntity);
    void _backHome(Ant &antEntity);
    void _backSugar(Ant &antEntity);
    void _randomMove(Ant &antEntity);

    // other manager
    void _decreaseSugarPhero();
    bool _antNeigbour(Ant &ant, Coord &neigbour);
    bool _sugarNeigbour(Ant &ant, Coord &neigbour);
    bool _nestNeigbour(Ant &ant);
    bool _sugarPheroNeigbour(Ant &ant, Coord &niegbour);

public:
    Manager(unsigned long delay,
            bool manual = false,
            unsigned int colony = 0,
            unsigned int sugar = 0,
            int cellDim = -1,
            Coord gridDim = Coord(0, 0));
    void start();
};
