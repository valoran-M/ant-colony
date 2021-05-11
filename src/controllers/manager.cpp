#include "controllers/manager.hpp"
#include "models/grid.hpp"
#include "models/coordinate.hpp"
#include <chrono>
#include <iostream>

Manager::Manager(unsigned long delay) : _delay(delay)
{
}

void Manager::start()
{
    Coord test = Coord(0, 0);

    _getData();
    _initialize();
    _display.display_init(&_data,
                          &_grid,
                          _data.caseSize);
    int i = 0;
    std::chrono::high_resolution_clock::time_point previousTime = std::chrono::high_resolution_clock::now();
    while (_display.isOpen())
    {
        _eventTraitment(_display.manageEvent());

        long delay = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - previousTime).count();
        if (delay < _delay * _data.speed || _data.state == Data::paused)
            continue;
        previousTime = std::chrono::high_resolution_clock::now();
        _display.setCell(test);
        test[0]++;
        _display.setCell(test, (uint8_t)255, (uint8_t)255, (uint8_t)255);
        if (test[0] > _data.width - 2)
            test[0] = 0;
    }
    _display.close();
}

void Manager::_eventTraitment(Display::events event)
{
    if (event == Display::events::reset)
        _reset();

    else if (event == Display::events::pause)
        _data.state =
            (_data.state != Data::paused) ? Data::paused : Data::running;
    else if (event == Display::events::speedUp)
        _data.speed -= (_data.speed > 0) ? 0.1 : 0;
    else if (event == Display::events::speedDown)
        _data.speed += 0.1;
}

void Manager::_reset()
{
    _data.reset();
    _grid.reset();

    _initialize();
    _display.setGird();
}