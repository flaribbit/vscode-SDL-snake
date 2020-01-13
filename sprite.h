#include "SDL.h"
#include "lodepng.h"
extern SDL_Renderer *renderer;

typedef struct _Sprite{
    int w,h;
    void *raw;
    SDL_Surface *surface;
    SDL_Texture *texture;
}Sprite;

void Sprite_new(Sprite *sp,char *path);
void Sprite_Draw(Sprite *sp,int x,int y);
void Sprite_Destroy(Sprite *sp);
