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

    /**
     * initalize sfml window
     * 
     * @return void
     *  
     * @confidence 2
     **/
    void _intitWindow();

    /**
     * initalize colony color
     * 
     * @param unsigned int number colony
     *
     * @return void
     *  
     * @confidence 2
     **/
    void _colorNeast(unsigned int numberColoy);

    /**
     * draw cell
     * 
     * @param Coord& coord of cell
     * @param sf::Color& color
     *
     * @return void
     *  
     * @confidence 2
     **/
    void _setCell(Coord &coord, sf::Color &color);

    /**
     * draw cell
     * 
     * @param Coord& coord of cell
     * @param uint8_t r
     * @param uint8_t g
     * @param uint8_t b
     * @param uint8_t a = 255
     *
     * @return void
     *  
     * @confidence 2
     **/
    void _setCell(Coord &coord,
                  uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

    /**
     * draw ant
     * 
     * @param Coord& coord of cell
     * @param sf::Color& color
     *
     * @return void
     *  
     * @confidence 2
     **/
    void _drawAnt(Coord &pos, sf::Color &color);

    /**
     * draw entity data
     * 
     * @return void
     *  
     * @confidence 2
     **/
    void _entityData();

    /**
     * draw sugar entity data
     * 
     * @return void
     *  
     * @confidence 2
     **/
    void _sugarDataDisplay();

    /**
     * draw ant entity data
     * 
     * @return void
     *  
     * @confidence 2
     **/
    void _antDataDisplay();

    /**
     * draw colony entity data
     * 
     * @return void
     *  
     * @confidence 2
     **/
    void _colonyDataDisplay();

    /**
     * add barrier in grid
     * 
     * @return void
     *  
     * @confidence 2
     **/
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

    /**
     * constructor of Display
     * 
     * @confidence 2
     **/
    Display();

    /**
     * initialize display
     * 
     * @param Data* Data object pointer
     * @param Data* Grid object pointer
     * @param unsigned int case size
     * 
     * @return void
     *  
     * @confidence 2
     **/
    void display_init(Data *data,
                      Grid *grid,
                      unsigned int caseSize);

    /**
     * manage window events
     * 
     * @return Display::events event for controllers
     *  
     * @confidence 2
     **/
    Display::events manageEvent();

    /**
     * update cell
     * 
     * @param Coord& coord of cell
     * 
     * @return void
     *  
     * @confidence 2
     **/
    void updataCell(Coord &cord);

    /**
     * check if window is open
     * 
     * @return bool true if window is open
     *  
     * @confidence 2
     **/
    bool isOpen() { return _window.isOpen(); }

    /**
     * close windows
     * 
     * @return void
     *  
     * @confidence 2
     **/
    void close();

    /**
     * display grid
     * 
     * @return void
     *  
     * @confidence 2
     **/
    void setGird();

    /**
     * display data
     * 
     * @return void
     *  
     * @confidence 2
     **/
    void setData();

    /**
     * manual colony generation
     * 
     * @return Coord
     *  
     * @confidence 2
     **/
    Coord getNestCreation();
};

static void _help();