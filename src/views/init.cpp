#include "views/display.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

Display::Display() : _antDataCoef(-1),
                     _colontyDataCoef(-1),
                     _sugarDataCase(NULL)
{
}

void Display::display_init(Data *data,
                           Grid *grid,
                           unsigned int caseSize)
{
    _grid = grid;
    _data = data;
    _height = _data->height;
    _width = _data->width;
    _caseSize = caseSize;
    _rectangle.setOutlineThickness(0);

    _intitWindow();
    _rectangleData.setSize(sf::Vector2f(_dataX, _window.getSize().y));
    _rectangleData.setOutlineThickness(1);
    _rectangleData.setOutlineColor(_lineColor);
    _rectangleData.setFillColor(_backgroundColor);
    _rectangleData.setPosition(_window.getSize().x - _dataX,
                               _most / 2);
    _colorNeast(_data->numberOfColony);

    if (!_font.loadFromFile("./font/Monospace.ttf"))
        exit(EXIT_FAILURE);

    setGird();
}

void Display::_intitWindow()
{
    if (_caseSize > 0)
        _window.create(sf::VideoMode(_height * _caseSize + _most + _dataX,
                                     _width * _caseSize + _most),
                       "Ant",
                       sf::Style::Close);
    else
        _window.create(sf::VideoMode(1920, 1080),
                       "ant", sf::Style::Fullscreen);
    _window.setActive(true);
    _window.setFramerateLimit(60);
}

void Display::_colorNeast(unsigned int numberColoy)
{
    for (unsigned int colony = 0; colony < numberColoy; colony++)
    {
        srand(colony * 200);
        _colonyColor.push_back(sf::Color(rand() % 255,
                                         rand() % 255,
                                         rand() % 255));
    }
}

void Display::setGird()
{
    _window.clear(_backgroundColor);

    _rectangle.setSize(sf::Vector2f(_caseSize, _caseSize));
    _rectangle.setOutlineColor(_lineColor);
    Coord coord(0, 0);
    for (coord[1] = 0; coord[1] < _height; coord[1]++)
        for (coord[0] = 0; coord[0] < _width; coord[0]++)
            updataCell(coord);
    setData();
}