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
  for (int i = 0; i < 3; i++){
    x = (rand() % 600) + 280;
    e[i] = initE(x, 435, 48, 31, true, pos_absolue_joueur);
  }
  /*e[0] = initE(450, 450, 30, 30, true, 0);
  e[1] = initE(380, 450, 30, 30, true, 0);*/
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

int detectCollid(int pos_perso, ennemy_t* en, SDL_Rect* struct_perso){
  /*if (pos_perso < en->pos_absolue + en->coo.w && pos_perso + struct_perso.w > en->pos_absolue){
    en->in_life = 0;
  } else{
    en->in_life = 1;
  }
  */
  if (SDL_HasIntersection(&en->coo, struct_perso) == SDL_TRUE){
    return 1;
  }
  else return 0;
}

int collid(int pos_perso, ennemy_t en[], SDL_Rect* struct_perso, int nbEnnemies){
  for (int i = 0; i<nbEnnemies;i++){
    if (detectCollid(pos_perso, &en[i], struct_perso) == 1)
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

