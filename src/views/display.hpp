#include "models/coordinate.hpp"
#include "models/data.hpp"
#include <SFML/Graphics.hpp>

class Display
{
private:
    Grid *_grid;
    Data *_data;
    sf::RenderWindow _window;
    sf::Event _event;
    sf::Color _backgroundColor = sf::Color(0, 22, 65);
    sf::Color _lineColor = sf::Color(0, 55, 162);
    std::vector<sf::Color> _colonyColor;

    sf::RectangleShape _rectangle;
    sf::CircleShape _circle;

    unsigned int _caseSize;
    unsigned int _most = 6;
    unsigned int _height;
    unsigned int _width;

    void _intitWindow();
    void _setGird();
    void _colorNeast(unsigned int numberColoy);

public:
    Display();

    void display_init(Data *data,
                      Grid *grid,
                      unsigned int caseSize);

    void manageEvent();
    void setCell(Coord &coord, sf::Color &color);
    void setCell(Coord &coord, uint8_t r, uint8_t g, uint8_t b);
    void drawAnt(Coord &pos, sf::Color &color);
    bool isOpen() { return _window.isOpen(); }
    void close();
};

static void _help();