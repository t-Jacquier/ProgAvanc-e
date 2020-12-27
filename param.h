//
// Created by timeojacquier on 10/12/2020.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
#include "fonction_SDL.h"

#ifndef PROJET_PARAM_H
#define PROJET_PARAM_H

void highScore(const char* nomFichier, int score);

void resethighScore(const char* nomFichier);


#endif //PROJET_PARAM_H
