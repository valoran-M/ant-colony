#include <random>

std::mt19937 random_generation(std::random_device{}());

unsigned int random_index(unsigned int lower, unsigned int higher)
{
    return std::uniform_int_distribution<unsigned int>(lower, higher)(random_generation);
}
