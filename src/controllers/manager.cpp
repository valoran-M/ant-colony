#include "controllers/manager.hpp"
#include "models/grid.hpp"
#include "models/coordinate.hpp"
#include <iostream>
#include <chrono>

Manager::Manager(unsigned long delay) : _delay(delay)
{
}

void Manager::start()
{
    _initialize();
    _display.grid(_grid, _data.width, _data.height, _data.caseSize);
    std::chrono::high_resolution_clock::time_point previousTime = std::chrono::high_resolution_clock::now();
    while (_display.isOpen())
    {
        _display.manageEvent();
        long delay = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - previousTime).count();
        if (delay < _delay)
            continue;
        previousTime = std::chrono::high_resolution_clock::now();
    }
    _display.close();
}
