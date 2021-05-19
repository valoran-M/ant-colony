#include "views/menu.hpp"
#include "views/display.hpp"
#include <iostream>
#include "SFML/Graphics.hpp"


Menu::Menu()
{
}

void Menu::init(float width, float height, sf::RenderWindow *window, sf::Font *font)
{
    _window = window;
    _font = font;
    _index = 0;
    _menu[0].setFont(*_font);
    _menu[0].setString("Restart");
    _menu[0].setFillColor(sf::Color(0,0,255));
    _menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    _menu[1].setFont(*_font);
    _menu[1].setFillColor(sf::Color(255,255,255));
    _menu[1].setString("Reset");
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
        _menu[_index].setFillColor(sf::Color(0,0,255));
    }
}

void Menu::_moveDown()
{
    if(_index < MAX_NUMBER_OF_ITEMS - 1)
    {
        _menu[_index].setFillColor(sf::Color(255,255,255));
        _index++;
        _menu[_index].setFillColor(sf::Color(0,0,255));
    }
}

int Menu::start()
{
    int compteur = 0;
    _drawMenu(compteur);
    sf::Event event;
    while (true)
    {
        compteur += 1;
        while (_window->pollEvent(event))
        {
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
                    return(_selectedItem());
                }
                break;
            }
            break;
        }
        _drawMenu(compteur);
        _window->display();
    }
    return 0;
}

void Menu::_drawMenu(int compteur)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(_window->getSize().x, _window->getSize().y));
    rectangle.setOutlineColor(sf::Color::Blue);
    rectangle.setOutlineThickness(5);
    rectangle.setFillColor(sf::Color((0 + compteur) % 255,(0 + compteur * 2) % 255,(0 + compteur * 3) % 255,2));
    rectangle.setPosition(0, 0);
    _window->draw(rectangle);
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        _window->draw(_menu[i]);
    }
}