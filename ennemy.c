//
// Created by timeo on 23/11/2020.
//

#include "ennemy.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
#include <time.h>
#include "fonction_SDL.h"
#include "perso.h"

ennemy_t initE(int x_set, int y_set, int w_set, int h_set, bool inLife, int pos_absolue_joueur){
    ennemy_t ennemy;
    ennemy.coo.x= x_set;
    ennemy.coo.y = y_set;
    ennemy.coo.w = w_set;
    ennemy.coo.h = h_set;
    ennemy.in_life = inLife;
    ennemy.pos_absolue = pos_absolue_joueur + x_set - 280; //L'origine du repère jeu est à 0 pour les coo du personnéages


    return ennemy;
}

ennemy_t* tabE(int pos_absolue_joueur){
  ennemy_t *e = malloc(10*sizeof(ennemy_t));
  int x = 0;
  srand(time(NULL));
  for (int i = 0; i < 10; i++){
    x = (rand() % 1000) + 480;
    e[i] = initE(x, 435, 48, 31, true, pos_absolue_joueur);
  }
  return e;
}

void freeEnnemy(ennemy_t* en[]){
    free(en[0]);
}

void copyEnnemies(SDL_Renderer* screen, SDL_Texture* text, ennemy_t tab[10], int nb_ennemies){
    for (int i = 0; i < nb_ennemies; i++){
        if (tab[i].in_life){
                SDL_RenderCopy(screen, text, NULL, &tab[i].coo);
        }
    }
}

int detectCollid(ennemy_t* en, SDL_Rect* struct_perso){
  if (en->in_life == 1) { //On vérifie que l'ennemi est bien en vie
    if (SDL_HasIntersection(&en->coo, struct_perso) == SDL_TRUE) {
      return 1;
    } else return 0;
  }
  return 0;
}

int collid(ennemy_t en[], SDL_Rect* struct_perso, int nbEnnemies){
  for (int i = 0; i<nbEnnemies;i++){
    if (detectCollid(&en[i], struct_perso) == 1)
      return 1;
  }
  return 0;
}



void moveEnnemyRight(ennemy_t* en, int nbEnnemies){
  for (int i = 0; i < nbEnnemies; i++)
    en[i].coo.x -= 10;
}

void moveEnnemyLeft(ennemy_t* en, int nbEnnemies){
  for (int i = 0; i < nbEnnemies; i++)
    en[i].coo.x += 10;
}

void collidProjectile(ennemy_t* en, projectile_t* tab, int nbEnnemies){
  for (int i = 0; i < nbEnnemies; i++){
    if (en[i].in_life) {
      for (int j = 0; j < NB_PROJECTILE; j++) {
        if (tab[j].shot) {
          if (SDL_HasIntersection(&en[i].coo, &tab[j].coo)) {
            en[i].in_life = 0;
            tab[j].shot = 0;
            tab[j].coo.x = 0;
          }
        }
      }
    }
  }
}

