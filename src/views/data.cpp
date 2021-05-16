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
    sf::Text text;
    std::string str_data;

    text.setFont(_font);
    text.setFillColor(sf::Color::White);
    text.setString("Sugar :");
    text.setPosition(_window.getSize().x - _dataX + 10,
                     15 + 40);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    _window.draw(text);

    str_data = "  coord x: " +
               std::to_string(_sugarDataCase->getCoord().getX()) +
               "\n        y: " +
               std::to_string(_sugarDataCase->getCoord().getY());

    text.setStyle(sf::Text::Regular);
    text.setString(str_data);
    text.setPosition(_window.getSize().x - _dataX + 10,
                     15 + 80);
    _window.draw(text);

    str_data = "  quantity: " + std::to_string(_sugarDataCase->getSugar());
    text.setStyle(sf::Text::Regular);
    text.setString(str_data);
    text.setPosition(_window.getSize().x - _dataX + 10,
                     15 + 160);

    _window.draw(text);
}