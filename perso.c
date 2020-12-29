//
// Created by timeojacquier on 08/12/2020.
//

#include "fonction_SDL.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
#include "perso.h"
#include "ennemy.h"

SDL_Rect init_perso(){
    SDL_Rect pos_perso;
    pos_perso.x = 280;
    pos_perso.y = 385;
    pos_perso.h = 80;
    pos_perso.w = 40;

    return pos_perso;
}

int move(int exec, SDL_Rect* perso, int horizontal_dep, SDL_Rect* pos_milieu, ennemy_t en[10]){
    if (horizontal_dep == 1){
        pos_milieu->x -= 10;
        moveEnnemyRight(en, 4);
        //en[1] = movePlayerRight(en[1]);
        //en[2] = movePlayerRight(en[2]);
        if (pos_milieu->x == -1800) //Si on arrive à gauche
            pos_milieu->x = 0; //On replace l'image du milieu
    }

    if (horizontal_dep == 2){
        pos_milieu->x += 10;
        moveEnnemyLeft(en, 4);
        if (pos_milieu->x == -480){ //Si on arrive à droite
            pos_milieu->x = -2280; //On replace l'image du milieu
        }
    }
    if (exec < JUMP_TIC){
        if (exec < JUMP_TIC / 2) {
            perso->y -= 10;
        }
        else{
            perso->y += 10;
        }
        return exec+1;
    }
    return JUMP_TIC;
}

