#include <stdio.h>
#include <SDL.h>
#include "sprite.h"

extern SDL_Renderer *renderer;

int WinMain(int argc, char *argv[])
{
    SDL_Window *window=SDL_CreateWindow("demo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_Event event;
    Sprite imgbody;
    Sprite_new(&imgbody,"body.png");
    char loop=1;
    while(loop){
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        Sprite_Draw(&imgbody,0,0);
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    loop=0;
                    break;
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}
