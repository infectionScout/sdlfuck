#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <SDL2/SDL.h>
#include <vector>
class Player{
    public:
        Player(int sw, int sh, int w, int h, std::string filePath, SDL_Renderer *renderer);
        void LoadMedia(SDL_Renderer *renderer, std::string file);
        void Flip(SDL_Renderer *renderer);
        void mainLoop(std::vector<std::string> p_array,std::vector<std::string> h_array,std::vector<std::string> r_array);
        int x;
        int y;
        SDL_Rect src;
        SDL_Rect dst;
    private:
        SDL_Texture* image;
        


};


#endif