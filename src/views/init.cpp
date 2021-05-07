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
    _setGird();
}

void Display::_intitWindow()
{
    if (_caseSize > 0)
        _window.create(sf::VideoMode(_height * _caseSize + _most,
                                     _width * _caseSize + _most),
                       "Ant",
                       sf::Style::Close);
    else
        _window.create(sf::VideoMode(),
                       "ant", sf::Style::Fullscreen);
    _window.setActive(true);
    _window.setFramerateLimit(60);
}

void Display::_colorNeast(unsigned int numberColoy)
{
    for (char colony = 0; colony < numberColoy; colony++)
    {
        srand(colony * 200);
        _colonyColor.push_back(sf::Color(rand() % 255,
                                         rand() % 255,
                                         rand() % 255));
    }
}

void Display::_setGird()
{
    _window.clear(_backgroundColor);

    _rectangle.setSize(sf::Vector2f(_caseSize, _caseSize));
    _rectangle.setOutlineColor(_lineColor);
    for (int i = 0; i < _height; i++)
        for (int j = 0; j < _width; j++)
        {
            Case &my_case = _grid->grid[i][j];
            if (my_case.getNest() != -1)
                setCell(my_case.getCoord(),
                        _colonyColor[my_case.getNest()]);
            else
                setCell(my_case.getCoord(), _backgroundColor);
        }
    drawAnt(Coord(0, 0), _colonyColor[2]);
}