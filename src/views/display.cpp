#include "views/display.hpp"
#include <SFML/Graphics.hpp>

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

void Display::setCell(Coord &coord, sf::Color color)
{
    _rectangle.setFillColor(_backgroundColor);
    _rectangle.setPosition(coord[0] * _caseSize + _most / 2,
                           coord[1] * _caseSize + _most / 2);
    _window.draw(_rectangle);
}

void Display::setCell(Coord &coord, uint8_t r, uint8_t g, uint8_t b)
{
    _rectangle.setFillColor(sf::Color(r, g, b));
    _rectangle.setPosition(coord[0] * _caseSize + _most / 2,
                           coord[1] * _caseSize + _most / 2);
    _window.draw(_rectangle);
}

void Display::close()
{
    _window.close();
}