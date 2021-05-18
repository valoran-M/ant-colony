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
    antEntity.getRotation() = newCase - antEntity.getCoord();
    _grid.getCase(antEntity.getCoord()).removeAnt();
    _grid.getCase(newCase).putAnt(antEntity.getNumber(),
                                  antEntity.getColony());
    antEntity.go_to(newCase);
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

void Manager::_antBirth(char colony)
{
    if (_data.colonies[colony].sugar > 15)
    {
        for (Coord &spawn : _data.colonies[colony].spawnableCase)
        {
            if (_grid.getCase(spawn).isEmpty())
            {
                _data.colonies[colony].sugar -= 10;
                _newAnt(spawn, colony);
                return;
            }
        }
    }
}

void Manager::_newAnt(Coord &pos, char colony)
{
    Coord &base = _data.colonies[colony].base;
    Coord rotate = Coord(0, 0);
    if (base.getX() < pos.getX() - 1)
        rotate[0] = 1;
    else if (base.getX() > pos.getX())
        rotate[0] = -1;
    else
        rotate[0] = 0;

    if (base.getY() < pos.getY() - 1)
        rotate[1] = -1;
    else if (base.getY() > pos.getY())
        rotate[1] = 1;
    else
        rotate[1] = 0;

    _data.colonies[colony].ants.push_back(Ant(_data.colonies[colony].ants.size(), pos, colony, rotate));
    _grid.getCase(pos).putAnt(_data.colonies[colony].ants.size() - 1, colony);
}