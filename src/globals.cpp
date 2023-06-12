#include "globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
bool checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB)
{
    bool xCollision = rectA.x + rectA.w >= rectB.x && rectB.x + rectB.w >= rectA.x;

    bool yCollision = rectA.y + rectA.h >= rectB.y && rectB.y + rectB.h >= rectA.y;

    return xCollision && yCollision;
}

bool checkKey(std::string key, std::vector<std::string> array){
    if (array.size() == 0){
        return false;
    }else{
        for (int i; i < array.size(); i++){
            if (array[i] == key){
                return true;
            }
        }
        return false;
    }
    
}



