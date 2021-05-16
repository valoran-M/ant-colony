#include "views/display.hpp"
#include <iostream>


Display::events Display::manageEvent()
{
    while (_window.pollEvent(_event))
        switch (_event.type)
        {
        case sf::Event::Closed:
            _window.close();
            break;

        case sf::Event::KeyPressed:
            switch (_event.key.code)
            {
            case sf::Keyboard::Escape:
                return pause;
            case sf::Keyboard::Up:
                return speedUp;
            case sf::Keyboard::Down:
                return speedDown;
            case sf::Keyboard::Q:
                _window.close();
                break;
            case sf::Keyboard::G:
                if (_rectangle.getOutlineThickness() == 1)
                    _rectangle.setOutlineThickness(0);
                else
                    _rectangle.setOutlineThickness(1);
                setGird();
                break;
            case sf::Keyboard::R:
                return reset;
            case sf::Keyboard::P:
                return pause;
            case sf::Keyboard::H:
                sf::Thread help(&_help);
                help.launch();
                break;
            }
        case sf::Event::MouseButtonPressed:
            unsigned int xGrid = (_event.mouseButton.x - _most) / _caseSize;
            unsigned int yGrid = (_event.mouseButton.y - _most) / _caseSize;
            if (xGrid > _data->width || yGrid > _data->height)
                break;

            switch (_event.mouseButton.button)
            {
            case sf::Mouse::Right:
                _antDataCoef = -1;
                _colontyDataCoef = -1;
                _sugarDataCase = NULL;
                if (_grid->getCase(xGrid, yGrid).isEmpty())
                    ;
                else if (_grid->getCase(xGrid, yGrid).containsAnt())
                {
                    _antDataCoef = _grid->getCase(xGrid, yGrid).getAnt();
                    _colontyDataCoef = _grid->getCase(xGrid, yGrid).getColony();
                }
                else if (_grid->getCase(xGrid, yGrid).containsNest())
                    _colontyDataCoef = _grid->getCase(xGrid, yGrid).getColony();
                else if (_grid->getCase(xGrid, yGrid).getSugar() != 0)
                    _sugarDataCase = &_grid->getCase(xGrid, yGrid);
                setGird();
                break;

            case sf::Mouse::Left:
                if (!_grid->getCase(xGrid, yGrid).isEmpty())
                    break;
                _grid->getCase(xGrid, yGrid).putSugar(20);
                updataCell(_grid->getCase(xGrid, yGrid).getCoord());
                break;
            }
            break;
        }
    _window.display();
    sf::sleep(sf::seconds(1.f / 60.f));
    return nothing;
}

static void _help()
{
    std::cout << std::endl
              << "***** help *****"
              << std::endl
              << "h     :   help"
              << std::endl
              << "g     :   display or delete borders"
              << std::endl
              << "r     :   reset"
              << std::endl
              << "p     :   pause"
              << std::endl
              << "q     :   quit"
              << std::endl
              << "UP    :   speed up"
              << std::endl
              << "DOWN  :   speed down"
              << std::endl
              << "ECHAP :   pause"
              << std::endl;
}