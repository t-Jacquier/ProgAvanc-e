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

void menu(SDL_Renderer* ecran, SDL_Event event, int pause, SDL_Texture* menu_back, SDL_Rect pos_menu);

SDL_Rect init_menu(SDL_Renderer* ecran, SDL_Texture* menu_back);

#endif //PROJET_PARAM_H
