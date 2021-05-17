#include "controllers/manager.hpp"
#include "controllers/random.hpp"
#include "models/ant.hpp"
#include <iostream>

void Manager::_antManger(unsigned int colony, unsigned int ant)
{
    Ant &antEntity = _data.colonies[colony].ants[ant];
    if (!antEntity.inLife())
        return;
    else if (antEntity.getSugar() != 0)
    {
        if (!_putSugar(antEntity))
            _backHome(antEntity);
    }
    else
    {
        if (!_getSugar(antEntity))
            _randomMove(antEntity);
    }
}

void Manager::_moveAnt(Ant &antEntity,
                       Coord &newCase)
{
    _grid.getCase(antEntity.getCoord()).removeAnt();
    _grid.getCase(newCase).putAnt(antEntity.getNumber(),
                                  antEntity.getColony());
    antEntity.go_to(newCase);
}

bool Manager::_putSugar(Ant &antEntity)
{
    std::vector<Coord> neigbours =
        antEntity.getCoord().getNeigbour(_data.width, _data.height);
    for (Coord &neigbour : neigbours)
        if (_grid.getCase(neigbour).getNest() == antEntity.getColony())
        {
            _data.colonies[antEntity.getColony()].sugar +=
                antEntity.getSugar();
            antEntity.dropSugar();
            _putSugarPhero(antEntity);
            return true;
        }
    return false;
}

void Manager::_backHome(Ant &antEntity)
{
    std::vector<Coord> neigbours =
        antEntity.getCoord().getNeigbour(_data.width, _data.height);
    Case closer;
    float nestPheroMax = _grid.getCase(antEntity.getCoord()).getNestPhero(antEntity.getColony());
    bool find = false;
    for (Coord &neigbour : neigbours)
    {
        if (_grid.getCase(neigbour).isEmpty() && _grid.getCase(neigbour).getNestPhero(antEntity.getColony()) > nestPheroMax)
        {
            find = true;
            closer = _grid.getCase(neigbour);
            nestPheroMax = _grid.getCase(neigbour).getNestPhero(antEntity.getColony());
        }
    }
    _putSugarPhero(antEntity);
    if (find)
        _moveAnt(antEntity, closer.getCoord());
    else
        _randomMove(antEntity);
}

bool Manager::_getSugar(Ant &antEntity)
{
    std::vector<Coord> neigbours =
        antEntity.getCoord().getNeigbour(_data.width, _data.height);
    for (Coord &neigbour : neigbours)
        if (_grid.getCase(neigbour).getSugar() > 0)
        {
            _grid.getCase(neigbour).decreasesSugar();
            antEntity.takeSugar(1);
            return true;
        }
    return false;
}

void Manager::_randomMove(Ant &antEntity)
{
    std::vector<Coord> neigbours =
        antEntity.getCoord().getNeigbour(
            _data.width, _data.height);
    std::vector<Coord> good;
    for (unsigned int i = 0; i < neigbours.size(); i++)
        if (_grid.getCase(neigbours[i]).isEmpty())
            good.push_back(neigbours[i]);
    if (good.size() > 0)
    {
        unsigned int rand = random_index(0, good.size() - 1);
        _moveAnt(antEntity, good[rand]);
    }
}