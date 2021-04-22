#include "controllers/manager.hpp"
#include <iostream>

void Manager::_inialise()
{
    _getData();
}

void Manager::_getData()
{
    do
    {
        std::cout << "Shape of grid : ";
        std::cin >> _data.width;
        std::cin >> _data.height;
    } while ((_data.width < 20 || _data.width > 100) ||
             (_data.height < 20 || _data.height > 100));
    do
    {
        std::cout << "Number of colony : ";
        std::cin >> _data.numberOfColony;
    } while (_data.numberOfColony > 6);
}

void Manager::_nestGeneration()
{
    
}