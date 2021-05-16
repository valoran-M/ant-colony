#include "controllers/manager.hpp"
#include <iostream>
#include <cstring>

void help();

int main(int argc, char const *argv[])
{
    unsigned int sugar = 0, colony = 0;
    int cellDim = -1;
    Coord gridDim(0, 0);
    bool man = false;

    for (int i = 1; i < argc; i++)
    {

        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
            help();
        else if (strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "--man") == 0)
            man = true;
        else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--colony") == 0)
        {
            int test = atoi(argv[++i]);
            colony = (test > 0) ? test : 0;
        }
        else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--sugar") == 0)
        {
            int test = atoi(argv[++i]);
            sugar = (test > 0) ? test : 0;
        }
        else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--largeness") == 0)
            cellDim = atoi(argv[++i]);
        else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--dimension") == 0)
            gridDim[0] = atoi(argv[++i]), gridDim[1] = atoi(argv[++i]);
    }
    std::cout << man;
    Manager simulation(1e9, man, colony, sugar, cellDim, gridDim);
    simulation.start();
    return 0;
}

void help()
{
    std::cout << "\thelp :\n"
              << "-m / --man                        : place colony manualy\n"
              << "-c / --colony number              : number of colony\n"
              << "-s / --sugar number               : number of sugar\n"
              << "-d / --dimension number number    : grid dimension\n"
              << "-l / --largeness number               : cell dimension\n";
    exit(EXIT_SUCCESS);
}