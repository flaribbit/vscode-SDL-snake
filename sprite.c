#include <stdio.h>
#include "sprite.h"
SDL_Renderer *renderer;

void Sprite_new(Sprite *sp,char *path){
    int error=lodepng_decode32_file((unsigned char **)&(sp->raw),&(sp->w),&(sp->h),path);
    if(error){
        printf("decoder error %u: %s\n", error, lodepng_error_text(error));
        return;
    }
    sp->surface=SDL_CreateRGBSurfaceWithFormatFrom(sp->raw,sp->w,sp->h,32,4*sp->w,SDL_PIXELFORMAT_RGBA32);
    if(!sp->surface){
        printf("Creating surface failed: %s\n", SDL_GetError());
        return;
    }
    sp->texture=SDL_CreateTextureFromSurface(renderer,sp->surface);
}

void Sprite_Draw(Sprite *sp,int x,int y){
    SDL_Rect src={0,0,sp->w,sp->h},dst={x,y,sp->w,sp->h};
    SDL_RenderCopy(renderer,sp->texture,&src,&dst);
}
