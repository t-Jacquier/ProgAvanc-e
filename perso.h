//
// Created by timeojacquier on 08/12/2020.
//
#include "fonction_SDL.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ennemy.h"
#include "header.h"

#ifndef PROJET_PERSO_H
#define PROJET_PERSO_H


struct s_projectile{
    SDL_Rect coo;
    int shot;
    int sens;
};

typedef struct s_projectile projectile_t;

void move_projectile(SDL_Rect* perso, projectile_t* tab); //Gere le mouvement des projectiles, qui reste collé au perso si pas tiré et qui avance sinon

SDL_Rect init_perso();

int move(int exec, SDL_Rect* perso, int horizontal_dep, SDL_Rect* pos_milieu, ennemy_t en[10]);

#endif //PROJET_PERSO_H
