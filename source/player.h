#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <SDL2/SDL.h>
class Player{
    public:
        Player(int sw, int sh, int w, int h, std::string filePath, SDL_Renderer *renderer);
        void LoadMedia(SDL_Renderer *renderer, std::string file);
        void Flip(SDL_Renderer *renderer);
        int x;
        int y;
        SDL_Rect src;
        SDL_Rect dst;
    private:
        SDL_Texture* image;
        


};


#endif