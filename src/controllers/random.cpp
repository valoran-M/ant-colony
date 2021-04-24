#include <random>

std::mt19937 gen(std::random_device{}());

unsigned int random_index(unsigned int lower, unsigned int higher)
{
    return std::uniform_int_distribution<unsigned int>(lower, higher)(gen);
}
