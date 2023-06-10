#include "globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_scancode.h>

bool checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB)
{
    bool xCollision = rectA.x + rectA.w >= rectB.x && rectB.x + rectB.w >= rectA.x;

    bool yCollision = rectA.y + rectA.h >= rectB.y && rectB.y + rectB.h >= rectA.y;

    return xCollision && yCollision;
}

