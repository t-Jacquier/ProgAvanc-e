//
// Created by timeo on 23/11/2020.
//


#include "fonction_SDL.h"
#include "header.h"

#ifndef PROJET_ENNEMY_H
#define PROJET_ENNEMY_H

struct ennemy_s{
    int x;
    int y;
    int life;
    int in_life;
};

typedef struct ennemy_s ennemy_t;

ennemy_t init(int x_set, int y_set);

#endif //PROJET_ENNEMY_H
