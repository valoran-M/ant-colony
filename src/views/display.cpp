#include "views/display.hpp"
#include <SFML/Graphics.hpp>

Display::Display()
{
}

void Display::newWindows(unsigned int height, unsigned int width)
{
    _height = height * 20;
    _width = width * 20;
    _window.create(sf::VideoMode(_height, _width), "Ant");
    _window.setFramerateLimit(4);
}

bool Display::manageEvent()
{
    while (_window.pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed)
            return true;
    }
    return false;
}

void Display::grid(Grid &grid, unsigned int height, unsigned int width)
{
    newWindows(height, width);
}

void Display::setCell(Coord &coord, uint8_t r, uint8_t g, uint8_t b)
{
}

void Display::close()
{
    _window.close();
}