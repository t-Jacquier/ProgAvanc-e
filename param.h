//
// Created by timeojacquier on 10/12/2020.
//
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
#include "fonction_SDL.h"
#include "ennemy.h"
#include "graphic.h"
#include "perso.h"

#ifndef PROJET_PARAM_H
#define PROJET_PARAM_H

/**
 * @brief Enregistre le score le plus haut dans un fichier externe
 * @param nomFichier Nom du fichier ou sera enregistré le score
 * @param position du personnage à la fin du jeu
 */
void highScore(const char* nomFichier, int score);

/**
 * @brief Remet à 0 le score le plus haut
 * @param nomFichier Nom du fichier ou sera enregistré le score
 */
void resethighScore(const char* nomFichier);

void menu(SDL_Renderer* ecran, SDL_Event event, int pause, SDL_Texture* menu_back, SDL_Rect pos_menu);

SDL_Rect init_menu();

/**
 * @brief Remet tout le jeu à 0 pour recommencer
 * @param fond Ensemble de coordonnées du fond du jeu
 * @param perso Ensemble de coordonnées du personnage
 * @param ennemy tableau d'ennemi
 * @param pos_perso Position du personnage
 */
void reset(SDL_Rect* fond, SDL_Rect* perso, ennemy_t *ennemy, int *pos_perso);

#endif //PROJET_PARAM_H
