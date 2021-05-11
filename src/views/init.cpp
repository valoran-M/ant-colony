#include "views/display.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

Display::Display()
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
    _rectangle.setOutlineThickness(1);

    _intitWindow();
    _colorNeast(_data->numberOfColony);
    setGird();
}

void Display::_intitWindow()
{
    if (_caseSize > 0)
        _window.create(sf::VideoMode(_height * _caseSize + _most,
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
            setCell(coord);
}