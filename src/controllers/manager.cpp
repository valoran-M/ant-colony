#include "controllers/manager.hpp"
#include "models/grid.hpp"
#include "models/coordinate.hpp"
#include <iostream>

Manager::Manager()
{
}

void Manager::start()
{
    _initialize();
    _display.grid(_grid, _data.width, _data.height, _data.caseSize);
    while (_display.isOpen())
    {
        _display.manageEvent();
    }
    _display.close();
}
