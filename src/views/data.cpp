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
    else if (_antDataCoef != NULL)
    {
        if (!_antDataCoef->inLife())
            _antDataCoef = NULL;
        else
            _antDataDisplay();
    }
    else if (_colontyDataCoef != NULL)
        _colonyDataDisplay();
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
               std::to_string(_sugarDataCase->getCoord().getY()) +
               "\n  quantity: " + std::to_string(_sugarDataCase->getSugar());

    text.setStyle(sf::Text::Regular);
    text.setString(str_data);
    text.setPosition(_window.getSize().x - _dataX + 10,
                     15 + 80);

    _window.draw(text);
}

void Display::_antDataDisplay()
{
    sf::Text text;
    std::string str_data;

    text.setFont(_font);
    text.setFillColor(_colonyColor[_antDataCoef->getColony()]);
    text.setString("Ant :");
    text.setPosition(_window.getSize().x - _dataX + 10,
                     15 + 40);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    _window.draw(text);

    str_data = "  coord x: " +
               std::to_string(_antDataCoef->getCoord().getX()) +
               "\n        y: " +
               std::to_string(_antDataCoef->getCoord().getY()) +
               "\n  rot   x: " +
               std::to_string(_antDataCoef->getRotation().getX()) +
               "\n        y: " +
               std::to_string(_antDataCoef->getRotation().getY()) +
               "\n  sugar: " + std::to_string(_antDataCoef->getSugar());

    text.setStyle(sf::Text::Regular);
    text.setString(str_data);
    text.setPosition(_window.getSize().x - _dataX + 10,
                     15 + 80);

    _window.draw(text);
}

void Display::_colonyDataDisplay()
{
    sf::Text text;
    std::string str_data;

    text.setFont(_font);
    text.setFillColor(_colonyColor[_colontyDataCoef->team]);
    text.setString("Colony :");
    text.setPosition(_window.getSize().x - _dataX + 10,
                     15 + 40);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    _window.draw(text);

    str_data = "  sugar: " + std::to_string(_colontyDataCoef->sugar) +
               "\n  ant:   " + std::to_string(_colontyDataCoef->getNbAnt());

    text.setStyle(sf::Text::Regular);
    text.setString(str_data);
    text.setPosition(_window.getSize().x - _dataX + 10,
                     15 + 80);

    _window.draw(text);
}