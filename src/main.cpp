#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "player.h"
#include "globals.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = NULL;


SDL_Surface* screenSurface = NULL;


SDL_Renderer* renderer = NULL;


SDL_Rect platform;

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
            if (TTF_Init() == -1){
                printf("TTF FAILED TO INIT! %s", SDL_GetError());
            }
            screenSurface = SDL_GetWindowSurface( window );

            
            
            SDL_UpdateWindowSurface( window );

            platform = {0,400,640,50};

            SDL_Event e; 
            bool quit = false; 

            Player jerry(51,49,51,49,"/home/weednation/sdlfuck/res/player.png", renderer);
            
            
                        

            SDL_Color black = {0, 0, 0};

            TTF_Font* sex = TTF_OpenFont("/home/weednation/sdlfuck/res/helvetica.ttf", 12);
            if (sex == NULL){
                printf("%s",SDL_GetError());
            }

            SDL_Surface* temp = TTF_RenderText_Solid(sex,"lorem ipsum i want to buy a car",black);
            SDL_Texture* leText = SDL_CreateTextureFromSurface(renderer, temp);
            int mWidth = temp->w;
            int mHeight = temp->h;
            

            SDL_Rect msg = {200,200,mWidth,mHeight};

            std::vector<std::string> pressedKeys;
            std::vector<std::string> heldKeys;
            std::vector<std::string> releasedKeys;
            std::string data = "No keys pressed";
            while( quit == false ){ 
                //pressedKeys.clear();
                SDL_DestroyTexture(leText);
                SDL_FreeSurface(temp);
                
                while( SDL_PollEvent( &e ) ){
                    if( e.type == SDL_QUIT ){
                        quit = true;
                    }
                    if (e.type == SDL_KEYDOWN){
                        pressedKeys.push_back( SDL_GetKeyName(e.key.keysym.sym) );
                        

                    }
                    

                }
                mWidth = temp->w;
                mHeight = temp->h;
                
                msg.x = jerry.x + 51;
                msg.y = jerry.y;
                msg.w = mWidth;
                msg.h = mHeight;

                
                jerry.mainLoop(); 
                if (pressedKeys.size() > 0){
                    data = "Pressed keys: ";
                    for (int i = 0; i < pressedKeys.size(); i++){
                        data += pressedKeys[i];
                    }
                } else {
                    data = "No keys pressed";
                }
                temp = TTF_RenderText_Solid(sex,data.c_str(),black);
                leText = SDL_CreateTextureFromSurface(renderer, temp);
                
                
                SDL_RenderClear( renderer );
                //INSERT ALL FLIPS BELOW ME
                SDL_SetRenderDrawColor(renderer, 0, 200, 0, 0xFF );
                SDL_RenderDrawRect(renderer,&platform);
                SDL_RenderDrawRect(renderer,&msg);
                SDL_SetRenderDrawColor(renderer, 155, 155, 155, 0xFF );

                jerry.Flip(renderer);
                SDL_RenderCopy(renderer,leText,NULL,&msg);

                //INSERT ALL FLIPS ABOVE ME
                SDL_RenderPresent( renderer );
                
                SDL_Delay(33);
            }
            
        SDL_DestroyWindow( window );

        
        SDL_Quit();

        return 0;

        }

    }
    
}