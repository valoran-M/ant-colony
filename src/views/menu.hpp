#pragma once
#include "views/display.hpp"
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
    Menu();
    void init(float width, float height, sf::RenderWindow *_window, sf::Font *_font);
    Display::events start();

private:
    int _index;
    sf::RenderWindow *_window;
    sf::Font *_font;
    sf::Text _menu[MAX_NUMBER_OF_ITEMS];
    void _moveUp();
    void _moveDown();
    int _selectedItem() { return _index; }
    void _drawMenu();
};