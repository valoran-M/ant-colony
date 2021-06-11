#include "controllers/manager.hpp"
#include <iostream>
#include <cstring>

void help();

int main(int argc, char const *argv[])
{
    unsigned int sugar = 2, colony = 2;
    int cellDim = 30;
    Coord gridDim(30, 30);
    bool man = false, texture = true;

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
        else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--textures") == 0)
            texture = true;
    }
    Manager simulation(1e9, man, colony, sugar, cellDim, gridDim, texture);
    simulation.start();
    return 0;
}

void help()
{
    std::cout << "ANT-COLONY\t\t\tUSER COMMANDE\n\n"
              << "NAME\n"
              << "\tAnt simulation\n\n"
              << "SYNOPSIS\n"
              << "\tant-colony [OPTION] ...\n\n"
              << "OPTIONS \n"
              << "\t-h / --help\n\t\tshow command\n"
              << "\t-t / --textures\n\t\tactive textures"
              << "\t-m / --man\n\t\tplace colony manualy\n"
              << "\t-c / --colony number\n\t\tnumber of colony\n"
              << "\t-s / --sugar number\n\t\tnumber of sugar\n"
              << "\t-l / --largeness number\n\t\tcell dimension\n"
              << "\t-d / --dimension number number\n\t\tgrid dimension\n";
    exit(EXIT_SUCCESS);
}