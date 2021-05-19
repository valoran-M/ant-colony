#include "menu.hpp"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "display.hpp"


Menu::Menu()
{
}

void Menu::init(float width, float height, sf::Window *window, sf::Font *font)
{
    _window = window;
    _font = font;
    _index = 0;
    _menu[0].setFont(*_font);
    _menu[0].setString("Restart");
    _menu[0].setFillColor(sf::Color(255,0,0));
    _menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    _menu[1].setFont(*_font);
    _menu[1].setFillColor(sf::Color(255,255,255));
    _menu[1].setString("Exit");
    _menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    _menu[2].setFont(*_font);
    _menu[2].setFillColor(sf::Color(255,255,255));
    _menu[2].setString("Exit");
    _menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
}

void Menu::_moveUp()
{
    if(_index > 0)
    {
        _menu[_index].setFillColor(sf::Color(255,255,255));
        _index--;
        _menu[_index].setFillColor(sf::Color(255,0,0));
    }
}

void Menu::_moveDown()
{
    if(_index < MAX_NUMBER_OF_ITEMS)
    {
        _menu[_index].setFillColor(sf::Color(255,255,255));
        _index++;
        _menu[_index].setFillColor(sf::Color(255,0,0));
    }
}

int Menu::start()
{
    sf::Event event;
    while (true)
    {
        while (_window->pollEvent(event))
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    _moveUp();
                    break;

                case sf::Keyboard::Down:
                    _moveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (_selectedItem())
                    {
                    case 0:
                        return 0;
                        break;

                    case 1:
                        return Display::reset;

                    case 2:
                        _window->close();
                        break;
                    }
                    break;
                }
                break;
            }
    }
    return 0;
}