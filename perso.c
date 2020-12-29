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
    pos_perso.y = 402;
    pos_perso.h = 60;
    pos_perso.w = 60;

    return pos_perso;
}



