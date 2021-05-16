#include "views/display.hpp"

void Display::_addbarrier()
{
    unsigned int yGrid = 0, xGrid = 0;
    bool stop = false, pressR = false, pressL = false;
    while (!stop)
    {
        while (_window.pollEvent(_event))
        {
            switch (_event.type)
            {
            case sf::Event::Closed:
                _window.close();
                exit(EXIT_SUCCESS);

            case sf::Event::KeyPressed:
                switch (_event.key.code)
                {
                case sf::Keyboard::B:
                    stop = true;
                    break;
                case sf::Keyboard::Q:
                    _window.close();
                    exit(EXIT_SUCCESS);
                }
            case sf::Event::MouseButtonPressed:
                if (_event.mouseButton.button == sf::Mouse::Left)
                    pressL = true;
                else if (_event.mouseButton.button == sf::Mouse::Right)
                    pressR = true;
                break;
            case sf::Event::MouseButtonReleased:
                xGrid = (_event.mouseButton.x - _most) / _caseSize;
                yGrid = (_event.mouseButton.y - _most) / _caseSize;
                if (xGrid > _data->width || yGrid > _data->height)
                    ;
                else if (_event.mouseButton.button == sf::Mouse::Left)
                {
                    pressL = false;
                    if (!_grid->getCase(xGrid, yGrid).getBarrier() &&
                        _grid->getCase(xGrid, yGrid).isEmpty())
                        _grid->getCase(xGrid, yGrid).putBarrier();
                }
                else if (_event.mouseButton.button == sf::Mouse::Right)
                {
                    pressR = false;
                    if (!_grid->getCase(xGrid, yGrid).getBarrier())
                        _grid->getCase(xGrid, yGrid).removeBarrier();
                }
                break;
            case sf::Event::MouseMoved:
                if (pressL)
                {
                    xGrid = (_event.mouseMove.x - _most) / _caseSize;
                    yGrid = (_event.mouseMove.y - _most) / _caseSize;
                    if (xGrid > _data->width || yGrid > _data->height)
                        break;
                    if (_grid->getCase(xGrid, yGrid).isEmpty())
                        _grid->getCase(xGrid, yGrid).putBarrier();
                }
                else if (pressR)
                {
                    xGrid = (_event.mouseMove.x - _most) / _caseSize;
                    yGrid = (_event.mouseMove.y - _most) / _caseSize;
                    if (xGrid > _data->width || yGrid > _data->height)
                        break;
                    _grid->getCase(xGrid, yGrid).removeBarrier();
                }
                break;
            }
        }
        setGird();
        _window.display();
    }
}