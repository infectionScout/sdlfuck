#include "player.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void Player::LoadMedia(SDL_Renderer *renderer, std::string file){
    SDL_Surface* temp = IMG_Load(file.c_str());
    if (temp == NULL){
        printf("IMG FAILED TO INTIIALIZE! Error:%s", SDL_GetError());
    } else {
        image = SDL_CreateTextureFromSurface( renderer, temp );
        SDL_FreeSurface(temp);
    }
}

Player::Player(int sw, int sh, int w, int h, std::string filePath, SDL_Renderer *renderer)
{
    LoadMedia(renderer, filePath);
    this->src = {0,0,51,49};
    this->dst = {200,200,51,49};



}

void Player::Flip(SDL_Renderer *renderer){
    SDL_RenderCopy(renderer, image, &src, &dst);
    
}
