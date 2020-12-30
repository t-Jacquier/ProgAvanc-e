#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
#include "fonction_SDL.h"
#include "ennemy.h"
#include "platform.h"
#include "perso.h"
#include "graphic.h"
#include "param.h"

int pause = 0; /*!<Jeu en pause ou non*/

int timer = 0; /*!<temps d'attente pour la texture du personnage lors d'un tir*/

int main(int argc, char *argv[]){
    SDL_Window* fenetre;  // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
    bool terminer = false;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());SDL_Quit();return EXIT_FAILURE;}// Créer la fenêtre
        fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
        if(fenetre == NULL) // En cas d’erreur
        {
            printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
            SDL_Quit();
            return EXIT_FAILURE;
            
        }
        
        //Contexte de rendu de l'écran
        SDL_Renderer* ecran;
        ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

        //Image centrale
        SDL_Texture* f_milieu = charger_image("fond6.bmp", ecran);
        SDL_Rect position_f_milieu = init_fond();

        SDL_Texture* menu_back = charger_image("menu.bmp", ecran);
        SDL_Rect pos_menu;
        pos_menu = init_menu(ecran, menu_back);

        SDL_Texture* perso = charger_image_transparente("perso2.bmp", ecran, 0, 255, 0);
        SDL_Texture* open_mouth = charger_image_transparente("open_mouth.bmp", ecran, 0, 255, 0);

        SDL_Texture* perso_reverse = charger_image_transparente("perso_reverse.bmp", ecran, 0, 255, 0);
        SDL_Texture* open_mouth_reverse = charger_image_transparente("open_mouth_reverse.bmp", ecran, 0, 255, 0);

        SDL_Texture* displayed_perso = perso;
        int sens; // Mémoire pour le tir

        SDL_Rect pos_perso = init_perso();
        
        int pos_perso_absolue = 0; //avancement du personnage sur la map, indépendant des coordonnées du fond



        int time_before = 0;
        int time_now = 0;
        int tms = 1000 / FPS; //Temps (en ms) durant une Frame à l'écran


        ennemy_t *e = tabE(pos_perso_absolue);

        SDL_Texture* enmi = charger_image_transparente("pasteque.bmp", ecran, 255, 0, 0);
        
        // Boucle principale
        while(!terminer)
        {
            SDL_RenderClear(ecran);
            while (SDL_PollEvent( &evenements ) )
                switch(evenements.type)
                {
                    case SDL_QUIT:
                        terminer = true; break;
                    case SDL_KEYDOWN:
                      if (evenements.key.keysym.sym==SDLK_ESCAPE){ //quitter le jeu
                        terminer = true;
                      }

                      if (evenements.key.keysym.sym==SDLK_d && !pause){ //mouvement à droite
                        position_f_milieu.x -= 10;
                        moveEnnemyRight(e, 4);
                        pos_perso_absolue +=10;
                        if (position_f_milieu.x == -1800)
                          position_f_milieu.x = 0;
                        displayed_perso = perso; // Sens du sprite
                      }

                      if (evenements.key.keysym.sym== SDLK_q && !pause){ //mouvement à gauche
                        if (pos_perso_absolue > 0) { // Pour ne pas dépasser le bord
                          position_f_milieu.x += 10;
                          moveEnnemyLeft(e, 4);
                          if (position_f_milieu.x == -480){ //Si on arrive à droite
                            position_f_milieu.x = -2280; //On replace l'image du milieu
                          }
                            pos_perso_absolue -= 10;
                        }
                        displayed_perso = perso_reverse;
                      }

                      //gestion du saut
                      if (evenements.key.keysym.sym == SDLK_SPACE && !pause){

                      }

                      if (evenements.key.keysym.sym == SDLK_s && !pause){
                        //test du sens du sprite originel
                        if (displayed_perso == perso) {
                          sens = 1;
                          displayed_perso = open_mouth;
                        }
                        if (displayed_perso == perso_reverse) {
                          sens = 2;
                          displayed_perso = open_mouth_reverse;
                        }
                        timer = 0;
                      }

                      if (evenements.key.keysym.sym == SDLK_p){
                        if (pause) pause = FALSE;
                        else pause = TRUE;
                      }
                      break;


                }

            //Gestion de la texture du perso
            if (timer >= 0 && timer < 40){
              if (sens == 1)
              displayed_perso = open_mouth;
              else
                displayed_perso = open_mouth_reverse;
              timer++;
            }

            if (timer == 40){
              timer = -1;
              sens = 0;
            }
            //Collage des textures
            SDL_RenderCopy(ecran, f_milieu, NULL, &position_f_milieu);
            menu(ecran, evenements, pause, menu_back, pos_menu);
            SDL_RenderCopy(ecran, displayed_perso, NULL, &pos_perso);
            copyEnnemies(ecran, enmi, e, 3);
            SDL_RenderPresent(ecran);
            //if (collid(pos_perso_absolue, e, &pos_perso, 3))
              //reset(&position_f_milieu, &pos_perso, e, &pos_perso_absolue);

            time_now = SDL_GetTicks();
            if (time_now - time_before > tms) //Si la frame est resté suffisamment longtemps, all good
                time_before = time_now;
            else{ // Sinon on temporise avant de passer
                SDL_Delay(tms - (time_now - time_before));
                time_before += tms;
            }

        }
        printf("%d \n",pos_perso_absolue);
        SDL_DestroyTexture(f_milieu);
        SDL_DestroyTexture(perso);
        SDL_DestroyRenderer(ecran);
        freeEnnemy(&e);
        highScore("score.txt", pos_perso_absolue);
        // Quitter SDL
        SDL_DestroyWindow(fenetre);



        SDL_Quit();
        return 0;
}
