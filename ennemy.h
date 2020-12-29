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

ennemy_t* tabE(int pos_absolue_joueur);

void freeEnnemy(ennemy_t* en[]);

void copyEnnemies(SDL_Renderer* screen, SDL_Texture* text, ennemy_t tab[10], int nb_ennemies);

void moveEnnemyRight(ennemy_t* en, int nbEnnemies);

void moveEnnemyLeft(ennemy_t* en, int nbEnnemies);

int detectCollid(int pos_perso, ennemy_t* en, SDL_Rect* struct_perso);

int collid(int pos_perso, ennemy_t en[], SDL_Rect* struct_perso, int nbEnnemies);


#endif //PROJET_ENNEMY_H
