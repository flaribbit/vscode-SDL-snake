#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "sprite.h"
#define MAXLEN 100 //最大长度
extern SDL_Renderer *renderer;
int frames=1;
struct{
    int x,y;
}body[MAXLEN],food; //蛇的身子和食物位置
int vx,vy,length; //蛇的移动方向和长度

void new(){
    int i;
    length=3;
    vx=30;
    vy=0;
    for(i=0;i<3;i++){
        body[i].x=30*(length-i);
        body[i].y=0;
    }
    food.x=rand()%10*30;
    food.y=rand()%10*30;
}

void move(){
    int i;
    if(body[0].x==food.x&&body[0].y==food.y){
        food.x=rand()%10*30;
        food.y=rand()%10*30;
        length++;
    }
    for(i=length-1;i>0;i--){
        body[i]=body[i-1];
    }
    body[0].x+=vx;
    body[0].y+=vy;
}

void draw(Sprite *imgbody){
    int i;
    for(i=0;i<length;i++){
        Sprite_Draw(imgbody,body[i].x,body[i].y);
    }
    Sprite_Draw(imgbody,food.x,food.y);
}

void key(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
            frames=-1;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
            case SDLK_UP:
                if(vy==0)vx=0,vy=-30;
                break;
            case SDLK_DOWN:
                if(vy==0)vx=0,vy=30;
                break;
            case SDLK_LEFT:
                if(vx==0)vx=-30,vy=0;
                break;
            case SDLK_RIGHT:
                if(vx==0)vx=30,vy=0;
                break;
            default:
                break;
            }
            break;
        }
    }
}

int WinMain(int argc, char *argv[])
{
    // SDL相关变量初始化
    SDL_Window *window=SDL_CreateWindow("demo",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // 贴图初始化
    Sprite imgbody;
    Sprite_new(&imgbody,"body.png");

    //游戏变量初始化
    new();
    while(frames){
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        draw(&imgbody);
        key();
        if(frames%6==0)move();
        SDL_RenderPresent(renderer);
        SDL_Delay(1000/60);
        frames++;
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return 0;
}
