#include "views/display.hpp"
#include <SFML/Graphics.hpp>
#include <string>
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
        case sf::Event::MouseButtonPressed:
            unsigned int xGrid = (_event.mouseButton.x - _most) / _caseSize;
            unsigned int yGrid = (_event.mouseButton.y - _most) / _caseSize;
            if (xGrid > _data->width || yGrid > _data->height)
                break;

            switch (_event.mouseButton.button)
            {
            case sf::Mouse::Right:
                _antDataCoef = -1;
                _colontyDataCoef = -1;
                _sugarDataCase = NULL;
                if (_grid->getCase(xGrid, yGrid).isEmpty())
                    ;
                else if (_grid->getCase(xGrid, yGrid).containsAnt())
                {
                    _antDataCoef = _grid->getCase(xGrid, yGrid).getAnt();
                    _colontyDataCoef = _grid->getCase(xGrid, yGrid).getColony();
                }
                else if (_grid->getCase(xGrid, yGrid).containsNest())
                    _colontyDataCoef = _grid->getCase(xGrid, yGrid).getColony();
                else if (_grid->getCase(xGrid, yGrid).getSugar() != 0)
                    _sugarDataCase = &_grid->getCase(xGrid, yGrid);
                setGird();
                break;

            case sf::Mouse::Left:
                if (!_grid->getCase(xGrid, yGrid).isEmpty())
                    break;
                _grid->getCase(xGrid, yGrid).putSugar(20);
                setCell(_grid->getCase(xGrid, yGrid).getCoord());
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
    int sugarPhero = 0;
    Case &cell = _grid->getCase(coord);
    if (cell.getAnt() != -1)
    {
        if (_colontyDataCoef == -1)
            setCell(cell.getCoord(), _backgroundColor);
        else
            setCell(cell.getCoord(),
                    _colonyColor[_colontyDataCoef].r,
                    _colonyColor[_colontyDataCoef].g,
                    _colonyColor[_colontyDataCoef].b,
                    _grid->getCase(cell.getCoord()).getNestPhero(_colontyDataCoef) * 100);
        drawAnt(cell.getCoord(), _colonyColor[cell.getColony()]);
    }

    else if (cell.getColony() != -1)
        setCell(cell.getCoord(), _colonyColor[cell.getColony()]);

    else if (cell.getSugar() != -1)
        setCell(cell.getCoord(), 255, 255, 255);

    else if (_colontyDataCoef != -1)
        setCell(cell.getCoord(),
                _colonyColor[_colontyDataCoef].r,
                _colonyColor[_colontyDataCoef].g,
                _colonyColor[_colontyDataCoef].b,
                _grid->getCase(cell.getCoord()).getNestPhero(_colontyDataCoef) * 100);
    else
        setCell(cell.getCoord(), _backgroundColor);
    if ((sugarPhero = cell.containsSugarPhero()) != -1)
    {
        sf::Color color(255, 255, 255, 100 * cell.getSugarPhero(sugarPhero));
        setCell(cell.getCoord(), color);
    }
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

void Display::setCell(Coord &coord, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    _rectangle.setFillColor(sf::Color(r, g, b, a));
    _rectangle.setPosition(coord[0] * _caseSize + _most / 2,
                           coord[1] * _caseSize + _most / 2);
    _window.draw(_rectangle);
}

void Display::close()
{
    _window.close();
}

void Display::setData()
{
    std::string lap = "lap : " + std::to_string(_data->lap);
    sf::Font font;

    if (!font.loadFromFile("./font/arial.ttf"))
        exit(EXIT_FAILURE);

    sf::Text lap_sf(lap, font);
    lap_sf.setPosition(_window.getSize().x - _dataX + 10,
                       15);
    lap_sf.setFillColor(sf::Color::White);

    _window.draw(_rectangleData);
    _window.draw(lap_sf);
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