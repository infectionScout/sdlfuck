#ifndef PLAYER_CPP
#define PLAYER_CPP
#include <string>
#include <SDL2/SDL.h>
class Player{
    public:
        Player(int sw, int sh, int w, int h, std::string filePath, SDL_Renderer *renderer);
        void LoadMedia(SDL_Renderer *renderer, std::string file);
        void Flip(SDL_Renderer *renderer);
        int x;
        int y;
    private:
        SDL_Rect* dst;
        SDL_Rect* src;
        SDL_Texture* image;
        


};


#endif