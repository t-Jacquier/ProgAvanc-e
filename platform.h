#include "fonction_SDL.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"



struct s_platform{
    SDL_Rect coo; 
    bool visible; 
};


typedef struct s_platform platform_t;

platform_t initP(int x, int y, int w, int h, bool est_visible);

platform_t* tabP(int nb_platform);

void freePlatform(platform_t* p[]);

void copyPlatform(SDL_Renderer* screen, SDL_Texture* text, platform_t tab[], int nb_platform);

void movePlatformRight(platform_t* p, int nb_platform);

void movePlatformLeft(platform_t* en, int nb_platform);

int detectCollid_platform(platform_t *p, SDL_Rect* struct_perso);
