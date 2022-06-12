#pragma once
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

namespace uitls
{
    inline float hireTimeInSeconds()
    {
        float t = SDL_GetTicks64();
        t *= 0.001f;
        return t;
    };
}
