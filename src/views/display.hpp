#include "models/coordinate.hpp"
#include "models/grid.hpp"
#include <SFML/Graphics.hpp>

class Display
{
private:
    sf::RenderWindow _window;
    sf::Event _event;
    unsigned int _height;
    unsigned int _width;

public:
    Display();
    void newWindows(unsigned int height, unsigned int width);
    void grid(Grid &grid, unsigned int height, unsigned int width);
    void close();
    bool manageEvent();
    void setCell(Coord &coord, uint8_t r, uint8_t g, uint8_t b);
};
