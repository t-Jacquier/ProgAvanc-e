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


SDL_Rect init_perso(){
    SDL_Rect pos_perso;
    pos_perso.x = 280;
    pos_perso.y = 402;
    pos_perso.h = 60;
    pos_perso.w = 60;

    return pos_perso;
}


projectile_t* init_projectile(){
  projectile_t *proj = malloc(NB_PROJECTILE * sizeof(projectile_t));
  for (int i = 0; i < NB_PROJECTILE; i++){
   proj[i].coo.x = 0;
   proj[i].coo.y = 0;
   proj[i].coo.w = 13;
   proj[i].coo.h = 13;
   proj[i].shot = FALSE;
   proj[i].sens = FALSE;
  }
  return proj;
}


void shoot_projectile(SDL_Rect* perso, projectile_t* tab, int sens){
  int i = 0;
  while (i < NB_PROJECTILE){
    if (!tab[i].shot) {
      tab[i].shot = 1;
      if (sens) tab[i].coo.x = perso->x + 30;
      else tab[i].coo.x = perso->x + 15;
      tab[i].coo.y = perso->y + 32; //Decallage pour arriver dans la bouche
      tab[i].sens = sens;
      i = NB_PROJECTILE; // Pour sortir de la boucle
    }
    i++;
  }
}

void move_projectile(SDL_Rect* perso, projectile_t* tab){
  for (int i = 0; i<NB_PROJECTILE; i++){
    if (tab[i].shot){
      if (tab[i].sens) {
        tab[i].coo.x += PROJECTILE_SPEED;
        if (tab[i].coo.x > perso->x + MAXIMUM_DISTANCE_PROJECTILE)
          tab[i].shot = FALSE;
      }
      else {
        tab[i].coo.x -= PROJECTILE_SPEED;
        if (tab[i].coo.x < perso->x - MAXIMUM_DISTANCE_PROJECTILE)
          tab[i].shot = FALSE;
      }
    }
  }
}

void copyProjectile(SDL_Renderer* renderer, SDL_Texture* texture, projectile_t* tab){
  for (int i = 0; i<NB_PROJECTILE; i++) {
    if (tab[i].shot){
      SDL_RenderCopy(renderer, texture, NULL, &tab[i].coo);
    }
  }
}


