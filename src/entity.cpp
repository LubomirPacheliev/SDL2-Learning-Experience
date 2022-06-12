#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

Entity::Entity(Vector2f pos, SDL_Texture *p_tex)
    : pos(pos), texture(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

Vector2f &Entity::getPos()
{
    return pos;
}

SDL_Texture *Entity::getTexture()
{
    return texture;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}