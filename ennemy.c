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

ennemy_t initE(int x_set, int y_set, int w_set, int h_set, bool inLife, int pos_absolue_joueur){
    ennemy_t ennemy;
    ennemy.coo.x= x_set;
    ennemy.coo.y = y_set;
    ennemy.coo.w = w_set;
    ennemy.coo.h = h_set;
    ennemy.in_life = inLife;
    ennemy.pos_absolue = pos_absolue_joueur + x_set - 600; //L'origine du repère jeu est à 0 pour les coo du personnéages

    return ennemy;
}

void copyEnnemies(SDL_Renderer* screen, SDL_Texture* text, ennemy_t tab[10], int nb_ennemies){
    for (int i = 0; i < nb_ennemies; i++){
        if (tab[i].in_life){
                SDL_RenderCopy(screen, text, NULL, &tab[i].coo);
        }
    }
}

void detectCollid(int pos_perso, ennemy_t* en, SDL_Rect struct_perso){
  if (pos_perso < en->coo.x + en->coo.w && pos_perso + struct_perso.w > en->coo.x){
    en->in_life = 0;
  } else{
    en->in_life = 1;
  }
}


ennemy_t movePlayerRight(ennemy_t en){
    en.coo.x -= 10;
    return en;
}

ennemy_t movePlayerLeft(ennemy_t en){
    en.coo.x += 10;
    return en;
}

