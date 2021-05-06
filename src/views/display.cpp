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
    _window.create(sf::VideoMode(_height + _most, _width + _most),
                   "Ant",
                   sf::Style::Close);
    _window.setActive(false);
    _window.setFramerateLimit(60);
}

void Display::manageEvent()
{
    //_window.clear(sf::Color(13, 34, 114));
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

void Display::setGird(unsigned int caseSize)
{
}

void Display::drawAnt(Coord pos, unsigned int caseSize)
{
    sf::CircleShape circle;
    circle.setRadius(caseSize / 3);
    circle.setFillColor(sf::Color::Cyan);
    circle.setOutlineColor(sf::Color::White);
    circle.setPosition(caseSize * pos[0] + caseSize / 2,
                       caseSize * pos[1] + caseSize / 2);
    _window.draw(circle);
}

void Display::grid(Grid &grid,
                   unsigned int height,
                   unsigned int width,
                   unsigned int caseSize)
{
    intitWindow(height, width, caseSize);
    _window.clear(_backgroundColor);
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(caseSize, caseSize));
    rectangle.setFillColor(_backgroundColor);
    rectangle.setOutlineColor(_lineColor);
    rectangle.setOutlineThickness(1);

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            rectangle.setPosition(i * caseSize + _most / 2,
                                  j * caseSize + _most / 2);
            _window.draw(rectangle);
        }
}

void Display::setCell(Coord &coord, uint8_t r, uint8_t g, uint8_t b)
{
}

void Display::close()
{
    _window.close();
}