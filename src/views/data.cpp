#include "views/display.hpp"
#include <string>

void Display::setData()
{
    std::string lap = "lap : " + std::to_string(_data->lap);
    sf::Font font;

    if (!font.loadFromFile("./font/arial.ttf"))
        exit(EXIT_FAILURE);

    sf::Text text(lap, font);
    text.setPosition(_window.getSize().x - _dataX + 10,
                     15);
    text.setFillColor(sf::Color::White);

    _window.draw(_rectangleData);
    _window.draw(text);
}