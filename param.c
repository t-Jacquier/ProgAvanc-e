//
// Created by timeojacquier on 10/12/2020.
//

#include "param.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
#include "fonction_SDL.h"

void highScore(const char* nomFichier, int score){
    FILE* file = fopen(nomFichier, "r+");

    int prec;
    if (file != NULL){ //Si il n'y a pas d'erreur à l'ouverture

        fseek(file, 13, SEEK_SET); //On se place à l'endroit où y a la valeur numérique
        char score_prec[10];
        fgets(score_prec, 10, file);
        prec = atoi(score_prec);

        if (prec < score){ //Si nouveau HIGH_score on l'écrit
            fseek(file, 13, SEEK_SET); //Remise au bon endroit pour écrire
            fprintf(file, "%d\n", score);

        }

        printf("%d", prec);
        printf("\n");

        fclose(file);
    }

}

void resethighScore(const char* nomFichier) {
    FILE *file = fopen(nomFichier, "r+");

    if (file != NULL) {
        fseek(file, 13, SEEK_SET);
        fprintf(file, "        \n");
        fclose(file);
    }
}

SDL_Rect init_menu(SDL_Renderer* ecran, SDL_Texture* menu_back){
  //menu_back = charger_image("menu.bmp", ecran);
  SDL_Rect pos;
  pos.x = 320;
  pos.y = 150;
  pos.w = 275;
  pos.h = 123;
  return pos;
}

void menu(SDL_Renderer* ecran, SDL_Event event, int pause, SDL_Texture* menu_back, SDL_Rect pos_menu){
  if (pause){
    SDL_RenderCopy(ecran, menu_back, NULL, &pos_menu);
  }
}

