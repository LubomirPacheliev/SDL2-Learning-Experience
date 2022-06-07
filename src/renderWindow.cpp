#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char *title, int width, int height) : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (window == NULL)
        std::cout << "Da window has forsaken us... " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *RenderWindow::loadTexture(const char *filePath)
{
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, filePath);
    if (texture == NULL)
        std::cout << "Failed to load a texture. Error: " << SDL_GetError() << std::endl;
    return texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture *texture)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;

    SDL_Rect dst;
    dst.x = 400;
    dst.y = 200;
    dst.w = 32 * 4;
    dst.h = 32 * 4;

    SDL_RenderCopy(renderer, texture, &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}