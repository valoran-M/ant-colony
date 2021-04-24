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
    _window = SDL_CreateWindow("ant simulator", SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               width,
                               height,
                               SDL_WINDOW_SHOWN);
    if (!_window)
    {
        fprintf(stderr, "Error window creation: %s\n", SDL_GetError());
        exit(-1);
    }
    _render = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

bool Display::manageEvent()
{
    bool close = false;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            close = true;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                close = true;
                break;
            }
        }
    }
    return close;
}

void Display::grid(std::size_t height, std::size_t width)
{
    newWindows(height, width);
    SDL_SetRenderDrawColor(_render, 0x0F, 0x11, 0x22, 0xFF);
    SDL_RenderClear(_render);


    SDL_RenderPresent(_render);
}

void Display::close()
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_render);
    SDL_Quit();
}