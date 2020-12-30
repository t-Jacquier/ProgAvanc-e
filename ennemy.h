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

/**
 * @brief Représente un ennemi
 */
struct s_ennemy{
    SDL_Rect coo; /*!< Ensemble de coordonnées*/
    int life; /*!< Niveau de vie*/
    int in_life; /*!< En vie ou non*/
    int pos_absolue; /*!< Position absolue par rapport au personnage */
};

typedef struct s_ennemy ennemy_t;


 /**
  * @brief Initialise un ennemi
  * @param x_set Position sur l'axe des abscisses
  * @param y_set Position sur l'axe des ordonnées
  * @param w_set Largeur du sprite
  * @param h_set Hauteur du sprite
  * @param inLife En vie ou non
  * @param pos_absolue_joueur Position absolue par rapport au personnage
  * @return Ennemi initialisé
  */
ennemy_t initE(int x_set, int y_set, int w_set, int h_set, bool inLife, int pos_absolue_joueur);

/**
 * @brief Initialise un tableau de 10 ennemis
 * @param pos_absolue_joueur Position absolue du joueur, pour fixé la distance
 * @return tableau d'ennemi dont la position a été initialisé au hasard
 */
ennemy_t* tabE(int pos_absolue_joueur);

/**
 * @brief Libère la mémoire du tableau passé
 * @param en tableau d'ennemis
 */
void freeEnnemy(ennemy_t* en[]);

/**
 * @brief affiche un tableau de 10 ennemies
 * @param screen Renderer où afficher
 * @param text Texture des ennemis
 * @param tab Tableau d'ennemis à afficher
 * @param nb_ennemies Nombre d'ennemis à afficher
 */
void copyEnnemies(SDL_Renderer* screen, SDL_Texture* text, ennemy_t tab[10], int nb_ennemies);

/**
 * @brief Décale un tableau d'ennemis par rapport aux mouvements à droite du personnage
 * @param en tableau d'ennemies
 * @param nbEnnemies Nombre d'ennemies à déplacer effectivement
 */
void moveEnnemyRight(ennemy_t* en, int nbEnnemies);

/**
 * @brief Décale un tableau d'ennemis par rapport aux mouvements à gauche du personnage
 * @param en tableau d'ennemies
 * @param nbEnnemies Nombre d'ennemies à déplacer effectivement
 */
void moveEnnemyLeft(ennemy_t* en, int nbEnnemies);

/**
 * @brief détecte la collision entre le personnage et un ennemi
 * @param en Ennemi à tester
 * @param struct_perso Ensemble de coordonnées du personnage
 * @return TRUE si collision FALSE sinon
 */
int detectCollid(ennemy_t* en, SDL_Rect* struct_perso);

/**
 * @brief détecte la collision entre le personnage et un tableau d'ennemis
 * @param en tableau d'ennemis à tester
 * @param struct_perso Ensemble de coordonnées du personnage
 * @param nbEnnemies Nombre d'ennemis à tester effectivement
 * @return TRUE si collision avec un ennemi, FALSE sinon
 */
int collid(ennemy_t en[], SDL_Rect* struct_perso, int nbEnnemies);


#endif //PROJET_ENNEMY_H
