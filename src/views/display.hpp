#include "models/coordinate.hpp"
#include "models/grid.hpp"
#include <SFML/Graphics.hpp>

class Display
{
private:
    sf::RenderWindow _window;
    sf::Event _event;
    sf::Color _backgroundColor = sf::Color(0, 22, 65);
    sf::Color _lineColor = sf::Color(67, 120, 222);
    sf::RectangleShape _rectangle;
    unsigned int _caseSize;
    unsigned int _most = 6;
    unsigned int _height;
    unsigned int _width;

public:
    Display();
    void intitWindow(unsigned int height,
                     unsigned int width,
                     unsigned int caseSize);
    void grid(Grid &grid,
              unsigned int height,
              unsigned int width,
              unsigned int caseSize);
    void close();
    void manageEvent();
    void setCell(Coord &coord, sf::Color color);
    void setCell(Coord &coord, uint8_t r, uint8_t g, uint8_t b);
    void drawAnt(Coord pos, unsigned int caseSize);
    void setGird(unsigned int caseSize);
    bool isOpen() { return _window.isOpen(); }
};
