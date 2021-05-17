#include "views/display.hpp"
#include <SFML/Graphics.hpp>

void Display::updataCell(Coord &coord)
{
    int sugarPhero = 0;
    Case &cell = _grid->getCase(coord);
    if (cell.getColony() != -1 && cell.getAnt() == -1)
        _setCell(cell.getCoord(), _colonyColor[cell.getColony()]);
    else if (cell.getSugar() > 0)
        _setCell(cell.getCoord(), 255, 255, 255);
    else if (cell.getBarrier())
        _setCell(cell.getCoord(), _barrierColor);
    else if ((sugarPhero = cell.containsSugarPhero()) != -1)
    {
        sf::Color color(255, 255, 255, 100 * cell.getSugarPhero(sugarPhero));
        _setCell(cell.getCoord(), color);
    }
    else
        _setCell(cell.getCoord(), _backgroundColor);
    if (_colontyDataCoef != NULL)
        _setCell(cell.getCoord(),
                 _colonyColor[_colontyDataCoef->team].r,
                 _colonyColor[_colontyDataCoef->team].g,
                 _colonyColor[_colontyDataCoef->team].b,
                 _grid->getCase(cell.getCoord()).getNestPhero(_colontyDataCoef->team) * 100);
    if (cell.getAnt() != -1)
    {
        if (&_data->colonies[cell.getColony()].ants[cell.getAnt()] == _antDataCoef)
            _drawAnt(cell.getCoord(), _red);
        else
            _drawAnt(cell.getCoord(), _colonyColor[cell.getColony()]);
    }
}

#include <iostream>

float Display::_vectToRot(Coord &rotation)
{
    float rotat = 0.;
    if (rotation[0] == 1)
        rotat = 90. - rotation[1] * 45. + 90.;
    if (rotation[0] == 0)
        rotat = 90. - rotation[1] * 90.;
    else
        rotat = 270. + rotation[1] * 45. + 90.;
    std::cout << rotat << std::endl;
    return rotat;
}

void Display::_drawAnt(Coord &pos, sf::Color &color)
{
    if (_caseSize < 20 || !_textures)
    {
        _circle.setRadius(_caseSize / 3);
        _circle.setFillColor(color);
        _circle.setPosition(sf::Vector2f(_caseSize * pos[0] + _caseSize / 3,
                                         _caseSize * pos[1] + _caseSize / 3));
        _window.draw(_circle);
    }
    else
    {
        _sprite.setColor(color);
        _sprite.setPosition(_caseSize * pos[0] + _caseSize / 3,
                            _caseSize * pos[1] + _caseSize / 5);
        _sprite.setRotation(0.);
        _sprite.rotate(_vectToRot(
            _data->colonies[_grid->getCase(pos).getColony()]
                .ants[_grid->getCase(pos).getAnt()]
                .getRotation()));

        _window.draw(_sprite);
    }
}

void Display::_setCell(Coord &coord, sf::Color &color)
{
    _rectangle.setFillColor(color);
    _rectangle.setPosition(coord[0] * _caseSize + _mostR / 2,
                           coord[1] * _caseSize + _mostL / 2);
    _window.draw(_rectangle);
}

void Display::_setCell(Coord &coord, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    _rectangle.setFillColor(sf::Color(r, g, b, a));
    _rectangle.setPosition(coord[0] * _caseSize + _mostR / 2,
                           coord[1] * _caseSize + _mostL / 2);
    _window.draw(_rectangle);
}

void Display::close()
{
    _window.close();
}