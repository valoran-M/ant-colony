#include "controllers/manager.hpp"
#include "models/grid.hpp"
#include "models/coordinate.hpp"
#include <iostream>

Manager::Manager() : rd(),
                     gen(rd())
{
}

void Manager::start()
{
    _initialize();
    bool quit = false;
    while (!quit)
    {
        quit = _display.manageEvent();
    }
    _display.close();
}
