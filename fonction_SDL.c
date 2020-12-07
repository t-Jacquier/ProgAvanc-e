#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonction_SDL.h"

SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*
renderer){

    
    SDL_Surface* img = SDL_LoadBMP(nomfichier);

    // Convertir la surface de l’image au format texture avant de l’appliquer
    //SDL_Texture* SDL_CreateTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface) ;
    return SDL_CreateTextureFromSurface(renderer, img);

    
}

SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b){
    SDL_Surface* img = SDL_LoadBMP(nomfichier);
    
    Uint32 key = SDL_MapRGB(img->format, r, g, b);
    
    int color = SDL_SetColorKey(img, SDL_TRUE, key);
    return SDL_CreateTextureFromSurface(renderer, img);
    
}

// SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer,TTF_Font *font, SDL_Color color){
//     SDL_Surface* txt =  TTF_RenderText_Solid(TTF_Font *font, const char *message, SDL_Color color);
//     return SDL_CreateTextureFromSurface(renderer, txt);
//     
// }
