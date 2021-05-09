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
    _initialize();
    _display.display_init(&_data,
                          &_grid,
                          _data.caseSize);

    std::chrono::high_resolution_clock::time_point previousTime = std::chrono::high_resolution_clock::now();
    while (_display.isOpen())
    {
        _display.manageEvent();
        
        long delay = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - previousTime).count();
        if (delay < _delay)
            continue;
        previousTime = std::chrono::high_resolution_clock::now();

        Coord test = Coord(0, 1);
        _display.setCell(test, (uint8_t)255, (uint8_t)255, (uint8_t)255);
    }
    _display.close();
}
