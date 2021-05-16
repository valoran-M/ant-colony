#include "views/display.hpp"
#include <SFML/Graphics.hpp>

void Display::drawAnt(Coord &pos, sf::Color &color)
{
    _circle.setRadius(_caseSize / 3);
    _circle.setFillColor(color);
    _circle.setPosition(sf::Vector2f(_caseSize * pos[0] + _caseSize / 3,
                                     _caseSize * pos[1] + _caseSize / 3));
    _window.draw(_circle);
}

void Display::setCell(Coord &coord)
{
    int sugarPhero = 0;
    Case &cell = _grid->getCase(coord);
    if (cell.getAnt() != -1)
    {
        if (_colontyDataCoef == -1)
            setCell(cell.getCoord(), _backgroundColor);
        else
            setCell(cell.getCoord(),
                    _colonyColor[_colontyDataCoef].r,
                    _colonyColor[_colontyDataCoef].g,
                    _colonyColor[_colontyDataCoef].b,
                    _grid->getCase(cell.getCoord()).getNestPhero(_colontyDataCoef) * 100);
        drawAnt(cell.getCoord(), _colonyColor[cell.getColony()]);
    }

    else if (cell.getColony() != -1)
        setCell(cell.getCoord(), _colonyColor[cell.getColony()]);

    else if (cell.getSugar() != -1)
        setCell(cell.getCoord(), 255, 255, 255);

    else if (_colontyDataCoef != -1)
        setCell(cell.getCoord(),
                _colonyColor[_colontyDataCoef].r,
                _colonyColor[_colontyDataCoef].g,
                _colonyColor[_colontyDataCoef].b,
                _grid->getCase(cell.getCoord()).getNestPhero(_colontyDataCoef) * 100);
    else
        setCell(cell.getCoord(), _backgroundColor);
    if ((sugarPhero = cell.containsSugarPhero()) != -1)
    {
        sf::Color color(255, 255, 255, 100 * cell.getSugarPhero(sugarPhero));
        setCell(cell.getCoord(), color);
    }
}

void Display::setCell(Coord &coord, sf::Color &color)
{
    _rectangle.setFillColor(color);
    _rectangle.setPosition(coord[0] * _caseSize + _most / 2,
                           coord[1] * _caseSize + _most / 2);
    _window.draw(_rectangle);
}

void Display::setCell(Coord &coord, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
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