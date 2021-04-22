#include "display.hpp"

#include <SDL2/SDL.h>

Display::Display()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
    {
        fprintf(stdout, "Faild to initialize SDL (%s)\n", SDL_GetError());
        exit(-1);
    }
}


void Display::newWindows(std::size_t height, std::size_t width)
{
    _windowMenu = SDL_CreateWindow("ant simulator", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   width,
                                   height,
                                   SDL_WINDOW_SHOWN);
    if (!_windowMenu)
    {
        fprintf(stderr, "Error window creation: %s\n", SDL_GetError());
        exit(-1);
    }
    SDL_Delay(3000);
}

void Display::close()
{
    SDL_DestroyWindow(_windowMenu);
    SDL_Quit();
}