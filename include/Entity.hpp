#pragma once
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity
{
public:
    Entity(Vector2f pos, SDL_Texture *p_tex);
    Vector2f &getPos();
    SDL_Texture *getTexture();
    SDL_Rect getCurrentFrame();

private:
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture *texture;
};