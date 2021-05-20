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
    /**
     * initialize simulation
     *
     * @place initialize.cpp
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _initialize();

    /**
     * reset simulation
     *
     * @place initialize.cpp
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _reset();

    /**
     * get data for the simulation
     *
     * @place initialize.cpp
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _getData();

    /**
     * teste if base is valid
     * 
     * @place initialize.cpp
     * 
     * @param Coord& base of nest
     * 
     * @return bool true if is valid
     * 
     * @confidence 2
     **/
    bool _baseTest(Coord &base);

    /**
     * generates colony
     *
     * @place initialize.cpp
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _colonnyGeneration();

    /**
     * generates random nest
     *
     * @place initialize.cpp
     * 
     * @param Colony& colony reference
     * @param std::vector<int>& vector refence
     * @param std::vector<int>& vector refence
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _randomNestCreation(Colony &colony,
                             std::vector<int> &x_grid,
                             std::vector<int> &y_grid);

    /**
     * generates random nest
     *
     * @place initialize.cpp
     * 
     * @param Colony& colony reference
     * @param Coord base of nest
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _nestCreation(Colony &colony, Coord base);

    /**
     * initailise nest Pheromone
     *
     * @place initialize.cpp
     * 
     * @param char colony marker
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _nestPheroInit(char colony);

    /**
     * create sugar
     * 
     * @place initialize.cpp
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _sugarCreation();

    /**
     * initialize spanable case of coord in colony
     * 
     * @place initialize.cpp
     * 
     * @param Coord const& coord
     * @param char colony
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _spawnableCase(Coord const &coord, char colony);

    /**
     * processes events
     * 
     * @place simulation.cpp
     * 
     * @param Display::events
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _eventTraitment(Display::events event);

    /**
     * update lap
     * 
     * @place simulation.cpp
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _lapUpdate();

    /**
     * manage ant
     * 
     * @place ant.cpp
     * 
     * @param unsinged int colony
     * @param unsigned int ant
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _antManger(unsigned int colony, unsigned int ant);

    /**
     * move ant
     * 
     * @place ant.cpp
     * 
     * @param Ant& antEntity
     * @param Coord& newCase
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _moveAnt(Ant &antEntity, Coord &newCase);

    /**
     * check if ant entity was near to other ant
     * 
     * @place ant.cpp
     * 
     * @param Ant& antEntity
     * 
     * @return bool true if ant kill other ant
     * 
     * @confidence 2
     **/
    bool _enemyKill(Ant &antEntity);

    /**
     * move ant
     * 
     * @place ant.cpp
     * 
     * @param Ant& antEntity
     * @param Coord& newCase
     * 
     * @return bool true if ant find sugar
     * 
     * @confidence 2
     **/
    bool _getSugar(Ant &antEntity);

    /**
     * ant put sugar in nest
     * 
     * @place ant.cpp
     * 
     * @param Ant& antEntity
     * 
     * @return bool true if ant put sugar in nest
     * 
     * @confidence 2
     **/
    bool _putSugar(Ant &antEntity);

    /**
     * ant back to its nest
     * 
     * @place ant.cpp
     * 
     * @param Ant& antEntity
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _backHome(Ant &antEntity);

    /**
     * test if sugar phero is good
     * 
     * @place ant.cpp
     * 
     * @param Ant& antEntity
     * 
     * @return bool true if find way
     * 
     * @confidence 2
     **/
    bool _sugarPheroMove(Ant &antEntity);

    /**
     * making a direction move for ant
     * 
     * @place ant.cpp
     * 
     * @param Ant& antEntity
     * 
     * @return void
     * 
     * @confidence 2
     **/
    bool _directionMove(Ant &antEntity);

    /**
     * making a random movement to the antEntity
     * 
     * @place ant.cpp
     * 
     * @param Ant& antEntity
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _randomMove(Ant &antEntity);

    /**
     * put sugar phermone in case where the ant is
     * 
     * @place initialize.cpp
     * 
     * @param Ant& antEntity
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _putSugarPhero(Ant &antEntity);

    /**
     * Decrese sugar pheromone in grid
     * 
     * @place initialize.cpp
     * 
     * @return void
     * 
     * @confidence 2 
     **/
    void _decreaseSugarPhero();

    /**
     * ant take sugar of other ant
     * 
     * @place ant.cpp
     * 
     * @return bool if take sugar
     * 
     * @confidence 2 
     **/
    bool _sugarTakeToAnt(Ant &antEntity);

    /**
     * ant get sugar of other ant
     * 
     * @place ant.cpp
     * 
     * @return bool if take sugar
     * 
     * @confidence 2 
     **/
    bool _sugarGetToAnt(Ant &antEntity);

    /**
     * reset nest pheromone
     * 
     * @return void
     * 
     * @confidence 2 
     **/
    void _resetNestPhero();

    /**
     * birth of ant
     * 
     * @place ant.cpp
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void _antBirth(char colony);

    /**
     * add new ant
     * 
     * @place ant.cpp
     * 
     * @param Coord& position of ant
     * @param char colony
     * 
     * @return void
     * 
     * @confidence 2 
     **/
    void _newAnt(Coord &pos, char colony);

public:
    /**
     * start simulation
     * 
     * @place simulation.cpp
     * 
     * @return void
     * 
     * @confidence 2
     **/
    void start();

    /**
     * constructor of manager
     * 
     * @place initialize.cpp
     * 
     * @param unsigned long delay
     * @param bool if colony spwan is manual
     * @param unsigned long number of colony
     * @param unsigned long number of sugar
     * @param int cell dimention
     * @param Coord grid dimention
     * @param bool textur activate
     *  
     * @confidence 2
     **/
    Manager(unsigned long delay,
            bool manual,
            unsigned int colony,
            unsigned int sugar,
            int cellDim,
            Coord gridDim,
            bool texture);
};
