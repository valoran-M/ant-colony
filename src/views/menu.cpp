#include "menu.hpp"
#include <iostream>
#include "SFML/Graphics.hpp"

Menu::Menu()
{
}

void Menu::init(float width, float height, sf::Window *window, sf::Font *font)
{
    _window = window;
    _font = font;
    _menu[0].setFont(*_font);
    _menu[0].setColor(sf::Color::Red);
    _menu[0].setString("Restart");
    _menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    _menu[1].setFont(*_font);
    _menu[1].setColor(sf::Color::White);
    _menu[1].setString("Exit");
    _menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    _menu[2].setFont(*_font);
    _menu[2].setColor(sf::Color::White);
    _menu[2].setString("Exit");
    _menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
}

void Menu::start()
{
    while (true)
    {
        /* code */
    }
       
}