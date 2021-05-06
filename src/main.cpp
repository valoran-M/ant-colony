#include "controllers/manager.hpp"

int main(int argc, char const *argv[])
{
    Manager simulation = Manager();
    simulation.start();
    return 0;
}
