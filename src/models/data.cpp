#include "models/data.hpp"

Data::Data() : state(menu),
               colonies(),
               lap(0),
               speed(1)
{
}

Data::Data(unsigned int colony,
           unsigned int sugar,
           int cellDim,
           Coord gridDim) : state(menu),
                            colonies(),
                            lap(0),
                            speed(1),
                            numberOfColony(colony),
                            sugar(sugar),
                            caseSize(cellDim),
                            width(gridDim[0]),
                            height(gridDim[1])
{
}

void Data::reset()
{
    colonies.clear();
    lap = 0;
}