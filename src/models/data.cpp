#include "models/data.hpp"

Data::Data() : state(menu),
               colonies(),
               lap(0),
               speed(1)
{
}

void Data::reset()
{
    colonies.clear();
}