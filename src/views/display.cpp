#include "views/display.hpp"
#include <SFML/Graphics.hpp>

void Display::updataCell(Coord &coord)
{
    int sugarPhero = 0;
    Case &cell = _grid->getCase(coord);
    if (cell.getAnt() != -1)
    {
        if (_colontyDataCoef == NULL)
            _setCell(cell.getCoord(), _backgroundColor);
        else
            _setCell(cell.getCoord(),
                     _colonyColor[_colontyDataCoef->team].r,
                     _colonyColor[_colontyDataCoef->team].g,
                     _colonyColor[_colontyDataCoef->team].b,
                     _grid->getCase(cell.getCoord()).getNestPhero(_colontyDataCoef->team) * 100);
        if (&_data->colonies[cell.getColony()].ants[cell.getAnt()] == _antDataCoef)
        {
            sf::Color red(255, 0, 0);
            _drawAnt(cell.getCoord(), red);
        }
        else
            _drawAnt(cell.getCoord(), _colonyColor[cell.getColony()]);
    }

    else if (cell.getColony() != -1)
        _setCell(cell.getCoord(), _colonyColor[cell.getColony()]);

    else if (cell.getSugar() != -1)
        _setCell(cell.getCoord(), 255, 255, 255);

    else if (_colontyDataCoef != NULL)
        _setCell(cell.getCoord(),
                 _colonyColor[_colontyDataCoef->team].r,
                 _colonyColor[_colontyDataCoef->team].g,
                 _colonyColor[_colontyDataCoef->team].b,
                 _grid->getCase(cell.getCoord()).getNestPhero(_colontyDataCoef->team) * 100);
    else
        _setCell(cell.getCoord(), _backgroundColor);

    if ((sugarPhero = cell.containsSugarPhero()) != -1)
    {
        sf::Color color(255, 255, 255, 100 * cell.getSugarPhero(sugarPhero));
        _setCell(cell.getCoord(), color);
    }
}

void Display::_drawAnt(Coord &pos, sf::Color &color)
{
    _circle.setRadius(_caseSize / 3);
    _circle.setFillColor(color);
    _circle.setPosition(sf::Vector2f(_caseSize * pos[0] + _caseSize / 3,
                                     _caseSize * pos[1] + _caseSize / 3));
    _window.draw(_circle);
}

void Display::_setCell(Coord &coord, sf::Color &color)
{
    _rectangle.setFillColor(color);
    _rectangle.setPosition(coord[0] * _caseSize + _most / 2,
                           coord[1] * _caseSize + _most / 2);
    _window.draw(_rectangle);
}

void Display::_setCell(Coord &coord, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    _rectangle.setFillColor(sf::Color(r, g, b, a));
    _rectangle.setPosition(coord[0] * _caseSize + _most / 2,
                           coord[1] * _caseSize + _most / 2);
    _window.draw(_rectangle);
}

void Display::close()
{
    _window.close();
}