#include "controllers/manager.hpp"
#include "models/grid.hpp"

#include <iostream>

Manager::Manager()
{
}

void Manager::start()
{
    std::size_t colony, width, height;
    do
    {
        std::cout << "Shape of grid : ";
        std::cin >> width;
        std::cin >> height;
    } while ((width > 100 || width < 20) ||
             (height < 20 || height > 100));
    do
    {
        std::cout << "Number of colony : ";
        std::cin >> colony;
    } while (colony > 6);
    _grid.intialise(width, height, colony);
}