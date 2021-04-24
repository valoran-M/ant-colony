#include <SDL2/SDL.h>

class Display
{
private:
    SDL_Window *_window;
    SDL_Renderer *_render;
    SDL_Event event;
    SDL_Rect _grid;
    unsigned int _height;
    unsigned int _width;

public:
    Display();
    void newWindows(std::size_t height, std::size_t width);
    void grid(std::size_t height, std::size_t width);
    void close();
    bool manageEvent();
};
