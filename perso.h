//
// Created by timeojacquier on 08/12/2020.
//
#include "fonction_SDL.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

#ifndef PROJET_PERSO_H
#define PROJET_PERSO_H

/**
 * @brief représentation d'un projectile lancé par le joueur
 */
struct s_projectile{
    SDL_Rect coo; /*!<Coordonnées du projectile */
    int shot; /*!<Projectile tiré ou non  */
    int sens; /*!<Sens de déplacement TRUE : Droite ; FALSE : Gauche */
};

typedef struct s_projectile projectile_t;

projectile_t* init_projectile();

/**
 * @brief set un projectil visible et actif quand il est tiré
 * @param perso coo du perso
 * @param tab tableau de projectiles
 * @param sens sens du personnage TRUE : Droite ; FALSE : Gauche
 */
void shoot_projectile(SDL_Rect* perso, projectile_t* tab, int sens);

/**
 * @brief update la position des projectiles quand ils sont tirés
 * @param perso coordonnées du personnage
 * @param tab tableau de projectiles
 */
void move_projectile(SDL_Rect* perso, projectile_t* tab);

/**
 * @brief affiche les projectiles
 * @param renderer renderer où la texture va être affichée
 * @param texture Texture de projectile
 * @param tab Tableau de projectile à afficher
 */
void copyProjectile(SDL_Renderer* renderer, SDL_Texture* texture, projectile_t* tab);

/**
 * @brief initialise les coordonnées du personnage en début de jeu
 * @return SDL_Rect contenant les coordonnées du sprite personnage
 */
SDL_Rect init_perso();

//int move(int exec, SDL_Rect* perso, int horizontal_dep, SDL_Rect* pos_milieu, ennemy_t en[10]);



#endif //PROJET_PERSO_H
