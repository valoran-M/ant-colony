#pragma once
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
    Menu();
    void init(float width, float height, sf::RenderWindow *_window, sf::Font *_font);
    int start();

private:
    int _index;
    sf::RenderWindow *_window;
    sf::Font *_font;
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Text _menu[MAX_NUMBER_OF_ITEMS];
    void _moveUp();
    void _moveDown();
    int _selectedItem() { return _index; }
    void _drawMenu();
};