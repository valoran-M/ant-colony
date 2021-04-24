#include "controllers/manager.hpp"

int main(int argc, char const *argv[])
{
    Manager simulation = Manager(1e9);
    simulation.start();
    return 0;
}
