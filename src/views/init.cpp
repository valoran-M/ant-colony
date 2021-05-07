#include "views/display.hpp"
#include <SFML/Graphics.hpp>

Display::Display()
{
}

void Display::display_init(Grid *grid,
                           unsigned int numberColoy,
                           unsigned int height,
                           unsigned int width,
                           unsigned int caseSize)
{
    _grid = grid;
    intitWindow(height, width, caseSize);
    _window.clear(_backgroundColor);

    setGird();
}

void Display::intitWindow(unsigned int height,
                          unsigned int width,
                          unsigned int caseSize)
{
    _height = height;
    _width = width;
    _caseSize = caseSize;
    if (caseSize > 0)
        _window.create(sf::VideoMode(_height * caseSize + _most,
                                     _width * caseSize + _most),
                       "Ant",
                       sf::Style::Close);
    else
        _window.create(sf::VideoMode(),
                       "ant", sf::Style::Fullscreen);
    _window.setActive(true);
    _window.setFramerateLimit(60);
}

void Display::setGird()
{
    _rectangle.setSize(sf::Vector2f(_caseSize, _caseSize));
    _rectangle.setOutlineColor(_lineColor);
    _rectangle.setOutlineThickness(1);
    for (int i = 0; i < _height; i++)
        for (int j = 0; j < _width; j++)
        {
            Case &my_case = _grid->grid[i][j];
            if (my_case.getNest() != -1)
            {
                setCell(my_case.getCoord(), 255, 0, 0);
            }
            else
                setCell(my_case.getCoord(), _backgroundColor);
        }
}