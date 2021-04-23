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
}
