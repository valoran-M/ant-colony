#include "views/display.hpp"
#include <string>

void Display::setData()
{
    std::string lap = "lap : " + std::to_string(_data->lap);

    sf::Text text(lap, _font);
    text.setPosition(_window.getSize().x - _dataX + 10,
                     15);
    text.setFillColor(sf::Color::White);

    _window.draw(_rectangleData);
    _window.draw(text);
    _entityData();
}

void Display::_entityData()
{
    if (_sugarDataCase != NULL)
        _sugarDataDisplay();
    else if (_antDataCoef != -1)
    {
    }
    else if (_colontyDataCoef != -1)
    {
    }
}

void Display::_sugarDataDisplay()
{
    std::string coord = "coord x : " +
                        std::to_string(_sugarDataCase->getCoord().getX()) +
                        "\n      y : " +
                        std::to_string(_sugarDataCase->getCoord().getY());
    sf::Text text(coord, _font);
    text.setPosition(_window.getSize().x - _dataX + 10,
                     15 + 30);
    text.setFillColor(sf::Color::White);

    _window.draw(text);
}