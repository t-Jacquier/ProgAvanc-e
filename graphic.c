//
// Created by timeojacquier on 08/12/2020.
//

#include "fonction_SDL.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
#include "graphic.h"

SDL_Rect init_fond() {
    SDL_Rect position_f_milieu;
    position_f_milieu.x = -600;
    position_f_milieu.y = 0;
    position_f_milieu.h = 600;
    position_f_milieu.w = 1800;

    return position_f_milieu;
}