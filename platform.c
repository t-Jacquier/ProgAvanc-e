#include "fonction_SDL.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "header.h"
#include "platform.h"

platform_t initP(int x, int y, int w, int h, bool est_visible){
    platform_t platform;
    platform.coo.x = x;
    platform.coo.y = y;
    platform.coo.w = w;
    platform.coo.h = h;
    platform.visible = est_visible;
    
    return platform;
}

platform_t* tabP(int nb_platform){
    platform_t *p= malloc(nb_platform*sizeof(platform_t));
    int x = 0;
    srand(time(NULL));
    for (int i = 0; i < nb_platform; i++){
        x = (rand() % 1000) + 500;
        p[i] = initP(x, 435, 48, 31, true);
    }
    return p;
}

void freePlatform(platform_t* p[]){
    free(p[0]);
}

void copyPlatform(SDL_Renderer* screen, SDL_Texture* text, platform_t tab[], int nb_platform){
    for (int i = 0; i < nb_platform; i++){
        if (tab[i].visible){
                SDL_RenderCopy(screen, text, NULL, &tab[i].coo);
        }
    }
}

void movePlatformRight(platform_t* p, int nb_platform){
  for (int i = 0; i < nb_platform; i++)
    p[i].coo.x -= 10;
}

void movePlatformLeft(platform_t* p, int nb_platform){
  for (int i = 0; i < nb_platform; i++)
    p[i].coo.x += 10;
}
