#include "models/coordinate.hpp"
#include "models/data.hpp"
#include "models/colony.hpp"
#include <SFML/Graphics.hpp>

class Display
{
private:
    Grid *_grid;
    Data *_data;
    sf::Font _font;
    sf::RenderWindow _window;
    sf::Event _event;
    sf::Color _backgroundColor = sf::Color(0, 22, 65);
    sf::Color _lineColor = sf::Color(0, 55, 162);
    sf::Color _barrierColor = sf::Color(86, 86, 86);
    std::vector<sf::Color> _colonyColor;

    sf::RectangleShape _rectangle;
    sf::RectangleShape _rectangleData;
    sf::CircleShape _circle;

    unsigned int _caseSize;
    unsigned int _most = 6;
    unsigned int _height;
    unsigned int _width;
    unsigned int _dataX = 300;
    bool pressL = false;

    Ant *_antDataCoef;
    Colony *_colontyDataCoef;
    Case *_sugarDataCase;

    void _intitWindow();
    void _colorNeast(unsigned int numberColoy);

    void _setCell(Coord &coord, sf::Color &color);
    void _setCell(Coord &coord,
                  uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
    void _drawAnt(Coord &pos, sf::Color &color);

    void _entityData();
    void _sugarDataDisplay();
    void _antDataDisplay();
    void _colonyDataDisplay();

    void _addbarrier();

public:
    enum events
    {
        pause,
        reset,
        speedUp,
        speedDown,
        nothing,
        pheroUpdate
    };
    Display();

    void display_init(Data *data,
                      Grid *grid,
                      unsigned int caseSize);

    Display::events manageEvent();
    void updataCell(Coord &cord);
    bool isOpen() { return _window.isOpen(); }
    void close();
    void setGird();
    void setData();

    Coord getNestCreation();
};

static void _help();