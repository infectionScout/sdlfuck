#include "player.h"
#include "globals.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

void Player::LoadMedia(SDL_Renderer *renderer, std::string file){
    SDL_Surface* temp = IMG_Load(file.c_str());
    if (temp == NULL){
        printf("IMG FAILED TO INTIIALIZE! Error:%s", SDL_GetError());
    } else {
        image = SDL_CreateTextureFromSurface( renderer, temp );
        SDL_FreeSurface(temp);
    }
}

Player::Player(int sw, int sh, int w, int h, std::string filePath, SDL_Renderer *renderer) : x(200), y(200)
{
    LoadMedia(renderer, filePath);
    this->src = {0,0,51,49};
    this->dst = {200,200,51,49};



}

void Player::Flip(SDL_Renderer *renderer){
    SDL_RenderCopy(renderer, image, &src, &dst);
    
}

void Player::mainLoop(std::vector<std::string> p_array,std::vector<std::string> h_array,std::vector<std::string> r_array){
    dst.x = this->x;
    dst.y = this->y;

    int moveH = checkKey("A",h_array) - checkKey("D",h_array);




}
