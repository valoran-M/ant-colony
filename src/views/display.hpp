#include <SDL2/SDL.h>

class Display
{
private:
    SDL_Window *_windowMenu;

public:
    Display();
    void newWindows(std::size_t height, std::size_t width);
    void close();
};
