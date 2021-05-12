#include "views/display.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Display::events Display::manageEvent()
{
    while (_window.pollEvent(_event))
        switch (_event.type)
        {
        case sf::Event::Closed:
            _window.close();
            break;

        case sf::Event::KeyPressed:
            switch (_event.key.code)
            {
            case sf::Keyboard::Escape:
                return pause;
            case sf::Keyboard::Up:
                return speedUp;
            case sf::Keyboard::Down:
                return speedDown;
            case sf::Keyboard::Q:
                _window.close();
                break;
            case sf::Keyboard::G:
                if (_rectangle.getOutlineThickness() == 1)
                    _rectangle.setOutlineThickness(0);
                else
                    _rectangle.setOutlineThickness(1);
                setGird();
                break;
            case sf::Keyboard::R:
                return reset;
            case sf::Keyboard::P:
                return pause;
            case sf::Keyboard::H:
                sf::Thread help(&_help);
                help.launch();
                break;
            }
            break;
        }
    _window.display();
    sf::sleep(sf::seconds(1.f / 60.f));
    return nothing;
}

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
    Case &cell = _grid->getCase(coord);
    if (cell.getAnt() != -1)
    {
        setCell(cell.getCoord(), _backgroundColor);
        drawAnt(cell.getCoord(), _colonyColor[cell.getColony()]);
    }
    else if (cell.getColony() != -1)
        setCell(cell.getCoord(), _colonyColor[cell.getColony()]);
    else if (cell.getSugar() != -1)
        setCell(cell.getCoord(), 255, 255, 255);
    else
        setCell(cell.getCoord(), _backgroundColor);
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
              << "r     :   reset"
              << std::endl
              << "p     :   pause"
              << std::endl
              << "q     :   quit"
              << std::endl
              << "UP    :   speed up"
              << std::endl
              << "DOWN  :   speed down"
              << std::endl
              << "ECHAP :   pause"
              << std::endl;
}