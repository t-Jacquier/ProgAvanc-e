//
// Created by timeo on 23/11/2020.
//

#include "ennemy.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
#include "fonction_SDL.h"

ennemy_t initE(int x_set, int y_set, int w_set, int h_set, bool inLife){
    ennemy_t ennemy;
    ennemy.coo.x= x_set;
    ennemy.coo.y = y_set;
    ennemy.coo.w = w_set;
    ennemy.coo.h = h_set;
    ennemy.in_life = inLife;

    return ennemy;
}

void copyEnnemies(SDL_Renderer* screen, SDL_Texture* text, ennemy_t tab[10], int nb_ennemies){
    for (int i = 0; i < nb_ennemies; i++){
        if (tab[i].in_life){
            SDL_RenderCopy(screen, text, NULL, &tab[i].coo);
        }
    }
}

ennemy_t movePlayerRight(ennemy_t en){
    en.coo.x -= 10;
    return en;
}

