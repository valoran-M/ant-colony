#pragma once

#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
    Menu();
    void init(float width, float height, sf::Window *_window, sf::Font *_font);
    void start();

private:
    int _index;
    sf::Window *_window;
    sf::Font *_font;
    sf::Text _menu[MAX_NUMBER_OF_ITEMS];
    void MoveUp();
    void MoveDown();
};