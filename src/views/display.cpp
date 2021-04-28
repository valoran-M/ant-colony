#include "views/display.hpp"
#include <SFML/Graphics.hpp>

Display::Display()
{
}

void Display::intitWindow(unsigned int height,
                          unsigned int width,
                          unsigned int caseSize)
{
    _height = height * caseSize;
    _width = width * caseSize;
    _window.create(sf::VideoMode(_height, _width),
                   "Ant",
                   sf::Style::Close);
    _window.setActive(false);
}

void Display::manageEvent()
{
    _window.pollEvent(_event);
    switch (_event.type)
    {
    case sf::Event::Closed:
        _window.close();
        break;

    case sf::Event::KeyPressed:
        switch (_event.key.code)
        {
        case sf::Keyboard::Escape:
            _window.close();
            break;
        }
        break;
    }
    _window.display();
}

void Display::setGird()
{
    
}

void Display::grid(Grid &grid,
                   unsigned int height,
                   unsigned int width,
                   unsigned int caseSize)
{
    intitWindow(height, width, caseSize);
    _window.clear(sf::Color());
}

void Display::setCell(Coord &coord, uint8_t r, uint8_t g, uint8_t b)
{
}

void Display::close()
{
    _window.close();
}