#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "Now SDL_Init has forsaken us like a mf... " << SDL_GetError() << std::endl;

    if (!IMG_Init(IMG_INIT_PNG))
        std::cout << "Now IMG_Init has forsaken us like a mf... " << SDL_GetError() << std::endl;

    RenderWindow window("GAM v0.0.1", 1280, 720);

    SDL_Texture *grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");
    Entity entities[4] = {
        Entity(90, 80, grassTexture),
        Entity(120, 80, grassTexture),
        Entity(150, 80, grassTexture),
        Entity(180, 80, grassTexture)};

    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
        }

        window.clear();

        for (int i = 0; i < 4; i++)
        {
            window.render(entities[i]);
        }

        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}