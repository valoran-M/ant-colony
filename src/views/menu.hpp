#pragma once

#include "SFML/Graphics.hpp"
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
    Menu(float width, float height);

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();

private:
    int _index;
    sf::Font _font;
    sf::Text _menu[MAX_NUMBER_OF_ITEMS];
};