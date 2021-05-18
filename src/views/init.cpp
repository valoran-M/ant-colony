#include "views/display.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>

Display::Display(bool texture) : _antDataCoef(NULL),
                                 _colontyDataCoef(NULL),
                                 _sugarDataCase(NULL),
                                 _textures(texture)
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
    _rectangle.setOutlineThickness(0);

    _texture.create(_caseSize, _caseSize);
    _texture.loadFromFile("./utility/ant.png");
    _texture.setSmooth(true);
    _sprite.setTexture(_texture);

    _intitWindow();

    _sprite.setScale(0.25 * caseSize * 0.03, 0.25 * caseSize * 0.03);

    _rectangleData.setSize(sf::Vector2f(_dataX, _window.getSize().y));
    _rectangleData.setOutlineThickness(1);
    _rectangleData.setOutlineColor(_lineColor);
    _rectangleData.setFillColor(_backgroundColor);
    _rectangleData.setPosition(_window.getSize().x - _dataX,
                               _mostL / 2);
    _colorNeast(_data->numberOfColony);

    if (!_font.loadFromFile("./utility/Monospace.ttf"))
        exit(EXIT_FAILURE);
    
    _menu.init(_window.getSize().x, _window.getSize().y, &_window, &_font);
    setGird();
}

void Display::_intitWindow()
{
    if (_caseSize > 0)
        _window.create(sf::VideoMode(_height * _caseSize + _mostR + _dataX,
                                     _width * _caseSize + _mostL),
                       "Ant",
                       sf::Style::Close);
    else
    {
        _caseSize = (1080 - _mostL / 2) / _data->width;
        _window.create(sf::VideoMode(1920, 1080),
                       "ant", sf::Style::Fullscreen);
    }
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
            updataCell(coord);
    setData();
}

Coord Display::getNestCreation()
{
    int xGrid = -1, yGrid = -1;
    while (xGrid == -1 && yGrid == -1)
    {
        while (_window.pollEvent(_event))
            switch (_event.type)
            {
            case sf::Event::Closed:
                _window.close();
                exit(EXIT_SUCCESS);

            case sf::Event::KeyPressed:
                switch (_event.key.code)
                {
                case sf::Keyboard::Q:
                    _window.close();
                    exit(EXIT_SUCCESS);
                case sf::Keyboard::G:
                    if (_rectangle.getOutlineThickness() == 1)
                        _rectangle.setOutlineThickness(0);
                    else
                        _rectangle.setOutlineThickness(1);
                    setGird();
                    break;
                }
            case sf::Event::MouseButtonPressed:
                unsigned int xGrid = (_event.mouseButton.x - _mostR) / _caseSize;
                unsigned int yGrid = (_event.mouseButton.y - _mostL) / _caseSize;
                if (xGrid > _data->width || yGrid > _data->height)
                    yGrid = xGrid = -1;
                else
                    return Coord(xGrid, yGrid);
                break;
            }
        setGird();
        _window.display();
    }
    return Coord(0, 0);
}