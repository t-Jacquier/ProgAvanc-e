//
// Created by timeo on 23/11/2020.
//


#include "fonction_SDL.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"


#ifndef PROJET_ENNEMY_H
#define PROJET_ENNEMY_H

struct s_ennemy{
    SDL_Rect coo;
    int life;
    int in_life;
    int pos_absolue;
};

typedef struct s_ennemy ennemy_t;

ennemy_t initE(int x_set, int y_set, int w_set, int h_set, bool inLife, int pos_absolue_joueur);

void copyEnnemies(SDL_Renderer* screen, SDL_Texture* text, ennemy_t tab[10], int nb_ennemies);

ennemy_t movePlayerRight(ennemy_t en);

ennemy_t movePlayerLeft(ennemy_t en);

void detectCollid(int pos_perso, ennemy_t* en, SDL_Rect struct_perso);


#endif //PROJET_ENNEMY_H
