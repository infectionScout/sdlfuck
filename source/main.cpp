#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "player.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = NULL;


SDL_Surface* screenSurface = NULL;


SDL_Renderer* renderer = NULL;

    
int main(int argc, char* args[]){
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL failed to initialize! Error: %s\n", SDL_GetError() );
    } else {
        if (!(IMG_Init(IMG_INIT_PNG))){
            printf("IMG_Init failed to initialize! Error %s", SDL_GetError());
        }
        window = SDL_CreateWindow("bitches house", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL){
            printf("Window failed to initialize! Error: %s", SDL_GetError());

        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL){
                printf("RENDERER FAILED TO INITIALIZE. ERROR:%s", SDL_GetError());
            }

            screenSurface = SDL_GetWindowSurface( window );

            SDL_SetRenderDrawColor(renderer, 155, 155, 155, 0xFF );
            
            SDL_UpdateWindowSurface( window );

            SDL_Event e; 
            bool quit = false; 

            Player jerry(51,49,51,49,"/home/weednation/sdlfuck/resource/player.png", renderer);
            
            while( quit == false ){ 
                while( SDL_PollEvent( &e ) ){
                     if( e.type == SDL_QUIT ){
                        quit = true;
                    }
                    SDL_RenderClear( renderer );
                    //INSERT ALL FLIPS BELOW ME

                    jerry.Flip(renderer);

                    //INSERT ALL FLIPS ABOVE ME
                    SDL_RenderPresent( renderer );
                } 
            }
            
        SDL_DestroyWindow( window );

        
        SDL_Quit();

        return 0;

        }
    }
    
}