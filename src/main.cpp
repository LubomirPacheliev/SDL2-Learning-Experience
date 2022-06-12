#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

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
    std::vector<Entity> entities = {
        Entity(Vector2f(90, 80), grassTexture),
        Entity(Vector2f(120, 80), grassTexture),
        Entity(Vector2f(150, 80), grassTexture),
        Entity(Vector2f(180, 80), grassTexture)};
    {
        Entity randomGrassBroski(Vector2f(210, 80), grassTexture);
        entities.push_back(randomGrassBroski);
    }

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

        for (Entity &e : entities)
        {
            window.render(e);
        }

        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}