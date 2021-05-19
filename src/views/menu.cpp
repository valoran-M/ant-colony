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
    _menu[0].setFillColor(sf::Color::Red);
    _menu[0].setString("Restart");
    _menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    _menu[1].setFont(*_font);
    _menu[1].setFillColor(sf::Color::White);
    _menu[1].setString("Exit");
    _menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    _menu[2].setFont(*_font);
    _menu[2].setFillColor(sf::Color::White);
    _menu[2].setString("Exit");
    _menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
}

int Menu::start()
{
    sf::Event event;
    bool open = true;
    while (open)
    {
        while (_window->pollEvent(event))
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    break;

                case sf::Keyboard::Down:
                    break;

                case sf::Keyboard::Return:
                    return 0;
                    break;
                }
                break;
            }
    }
    return 0;
}