#include "views/display.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

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
        case sf::Keyboard::Q:
            _window.close();
            break;
        case sf::Keyboard::G:
            if (_rectangle.getOutlineThickness() == 1)
                _rectangle.setOutlineThickness(0);
            else
                _rectangle.setOutlineThickness(1);
            _setGird();
            break;
        case sf::Keyboard::H:
            sf::Thread help(&_help);
            help.launch();
            break;
        }
        break;
    }
    _window.display();
}

void Display::drawAnt(Coord pos, sf::Color &color)
{
    _circle.setRadius(_caseSize / 3);
    _circle.setFillColor(color);
    _circle.setPosition(_caseSize * pos[0] + _caseSize / 3,
                        _caseSize * pos[1] + _caseSize / 3);
    _window.draw(_circle);
}

void Display::setCell(Coord &coord, sf::Color &color)
{
    _rectangle.setFillColor(color);
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

static void _help()
{
    std::cout << std::endl
              << "***** help *****"
              << std::endl
              << "h     :   help"
              << std::endl
              << "g     :   display or delete borders"
              << std::endl
              << "q     :   quit"
              << std::endl
              << "UP    :   speed up"
              << std::endl
              << "DOWN  :   speed down"
              << std::endl
              << "ECHAP :   quit"
              << std::endl;
}