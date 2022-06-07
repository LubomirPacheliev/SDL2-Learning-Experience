#pragma once
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
public:
    RenderWindow(const char *title, int width, int height);
    SDL_Texture *loadTexture(const char *filePath);
    void cleanUp();
    void clear();
    void render(SDL_Texture *texture);
    void display();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};