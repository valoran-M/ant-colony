#include "views/display.hpp"
#include <iostream>

Display::events Display::manageEvent()
{
    unsigned int xGrid, yGrid;
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
                switch(_menu.start())
                {
                    case 0:
                        break;
                    
                    case 1:
                        return Display::events::reset;
                        break;
                    case 2:
                        _window.close();
                        break;
                }
            case sf::Keyboard::Up:
                return Display::events::speedUp;
            case sf::Keyboard::Down:
                return Display::events::speedDown;
            case sf::Keyboard::Q:
                _window.close();
                break;
            case sf::Keyboard::B:
                _addbarrier();
                return Display::events::pheroUpdate;
            case sf::Keyboard::N:
                return Display::events::pheroUpdate;
            case sf::Keyboard::G:
                if (_rectangle.getOutlineThickness() == 1)
                    _rectangle.setOutlineThickness(0);
                else
                    _rectangle.setOutlineThickness(1);
                setGird();
                break;
            case sf::Keyboard::R:
                return Display::events::reset;
            case sf::Keyboard::P:
                return Display::events::pause;
            case sf::Keyboard::H:
                sf::Thread help(&_help);
                help.launch();
                break;
            }
        case sf::Event::MouseButtonPressed:
            xGrid = (_event.mouseButton.x - _mostR) / _caseSize;
            yGrid = (_event.mouseButton.y - _mostL) / _caseSize;
            if (xGrid > _data->width || yGrid > _data->height)
                break;

            switch (_event.mouseButton.button)
            {
            case sf::Mouse::Right:
                _antDataCoef = NULL;
                _colontyDataCoef = NULL;
                _sugarDataCase = NULL;
                if (_grid->getCase(xGrid, yGrid).isEmpty())
                    ;
                else if (_grid->getCase(xGrid, yGrid).containsAnt())
                {
                    _antDataCoef = &_data->colonies[_grid->getCase(xGrid, yGrid).getColony()]
                                        .ants[_grid->getCase(xGrid, yGrid).getAnt()];
                }
                else if (_grid->getCase(xGrid, yGrid).containsNest())
                    _colontyDataCoef = &_data->colonies[_grid->getCase(xGrid, yGrid).getColony()];
                else if (_grid->getCase(xGrid, yGrid).getSugar() != 0)
                    _sugarDataCase = &_grid->getCase(xGrid, yGrid);
                setGird();
                break;

            case sf::Mouse::Left:
                if (!_grid->getCase(xGrid, yGrid).isEmpty())
                    break;
                pressL = true;
                _grid->getCase(xGrid, yGrid).putSugar(20);
                updataCell(_grid->getCase(xGrid, yGrid).getCoord());
                break;
            }
            break;
        case sf::Event::MouseButtonReleased:
            pressL = false;
            break;
        case sf::Event::MouseMoved:
            if (pressL)
            {
                xGrid = (_event.mouseMove.x - _mostR) / _caseSize;
                yGrid = (_event.mouseMove.y - _mostL) / _caseSize;
                if (xGrid > _data->width || yGrid > _data->height)
                    break;
                if (!_grid->getCase(xGrid, yGrid).isEmpty())
                    break;
                _grid->getCase(xGrid, yGrid).putSugar(20);
                updataCell(_grid->getCase(xGrid, yGrid).getCoord());
                break;
            }
        }
    _window.display();
    sf::sleep(sf::seconds(1.f / 60.f));
    return Display::events::nothing;
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
              << "b     :   barrier"
              << std::endl
              << "n     :   reste nest phero"
              << std::endl
              << "UP    :   speed up"
              << std::endl
              << "DOWN  :   speed down"
              << std::endl
              << "ECHAP :   pause"
              << std::endl;
}