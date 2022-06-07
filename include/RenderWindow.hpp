#pragma once
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
public:
    RenderWindow(const char *title, int width, int height);
    void cleanUp();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};