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

int saut = -1; /*!<timer pour le saut*/


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
        srand (time (NULL));
        
        //Contexte de rendu de l'écran
        SDL_Renderer* ecran;
        ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

        //Image centrale
        SDL_Texture* f_milieu = charger_image("fond6.bmp", ecran);
        SDL_Rect position_f_milieu = init_fond();

        SDL_Texture* menu_back = charger_image("menu.bmp", ecran);
        SDL_Rect pos_menu;
        pos_menu= init_menu();

        SDL_Texture* projectile_texture = charger_image_transparente("projectile.bmp", ecran, 0, 255, 0);

        SDL_Texture* perso = charger_image_transparente("perso2.bmp", ecran, 0, 255, 0);
        SDL_Texture* open_mouth = charger_image_transparente("open_mouth.bmp", ecran, 204, 0, 0);

        SDL_Texture* perso_reverse = charger_image_transparente("perso_reverse.bmp", ecran, 0, 255, 0);
        SDL_Texture* open_mouth_reverse = charger_image_transparente("open_mouth_reverse.bmp", ecran, 204, 0, 0);

        SDL_Texture* displayed_perso = perso;
        int sens; // Mémoire pour le tir

        SDL_Rect pos_perso = init_perso();
        
        int pos_perso_absolue = 0; //avancement du personnage sur la map, indépendant des coordonnées du fond



        int time_before = 0;
        int time_now = 0;
        int tms = 1000 / FPS; //Temps (en ms) durant une Frame à l'écran


        ennemy_t *e = tabE(pos_perso_absolue);

        projectile_t* proj = init_projectile();

        SDL_Texture* enmi = charger_image_transparente("pasteque.bmp", ecran, 255, 0, 0);
        
        platform_t *p = tabP(5);
        
        SDL_Texture* platform = charger_image_transparente("platform.bmp", ecran, 255, 0, 0);



        
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
                        moveEnnemyRight(e, 10);
                        movePlatformRight(p, 5);
                        pos_perso_absolue +=10;
                        if (position_f_milieu.x == -1800)
                          position_f_milieu.x = 0;
                        displayed_perso = perso; // Sens du sprite
                      }


                      if (evenements.key.keysym.sym== SDLK_q && !pause){ //mouvement à gauche
                        if (pos_perso_absolue > 0) { // Pour ne pas dépasser le bord
                          position_f_milieu.x += 10;
                          moveEnnemyLeft(e, 10);
                          movePlatformLeft(p, 5);
                          if (position_f_milieu.x == -480){ //Si on arrive à droite
                            position_f_milieu.x = -2280; //On replace l'image du milieu
                          }
                            pos_perso_absolue -= 10;
                        }
                        displayed_perso = perso_reverse;
                      }

                      //gestion du saut
                      if (evenements.key.keysym.sym == SDLK_SPACE && !pause){
                        if (saut == -1)//Si il n'y a pas déjà un saut en cours
                          saut = 0;
                      }

                      if (evenements.key.keysym.sym == SDLK_s && !pause){
                        //test du sens du sprite originel
                        if (displayed_perso == perso) {
                          sens = 1;
                          displayed_perso = open_mouth;
                        }
                        if (displayed_perso == perso_reverse) {
                          sens = 0;
                          displayed_perso = open_mouth_reverse;
                        }
                        shoot_projectile(&pos_perso, proj, sens);
                        timer = 0;
                      }

                      if (evenements.key.keysym.sym == SDLK_p){
                        if (pause) pause = FALSE;
                        else pause = TRUE;
                      }
                      break;

                  case SDL_MOUSEBUTTONDOWN:
                    if (evenements.button.button == SDL_BUTTON_LEFT){
                      if (pause){
                        if (evenements.button.x > 213 && evenements.button.x < 388 && evenements.button.y > 230 && evenements.button.y < 280){
                          terminer = true;
                        }
                      }
                    }
                    break;
                }

            //Gestion de la texture du perso
            if (timer >= 0 && timer < 10){
              if (sens == 1)
              displayed_perso = open_mouth;
              else
                displayed_perso = open_mouth_reverse;
              timer++;
            }

            if (timer == 10){
              if (sens == 1)
                displayed_perso = perso;
              else
                displayed_perso = perso_reverse;
              timer = -1;
              sens = 0;
            }

            if (saut >= 0 && saut < 10){
              saut += 1;
              pos_perso.y -= 5;
            }
            if (saut >= 10 && saut < 20){
              saut += +1;
              pos_perso.y += 5;
            }
            if (saut == 20)
              saut = -1;

            move_projectile(&pos_perso, proj);
            collidProjectile(e, proj, 10);
            //Collage des textures
            SDL_RenderCopy(ecran, f_milieu, NULL, &position_f_milieu);
            menu(ecran, evenements, pause, menu_back, pos_menu);
            SDL_RenderCopy(ecran, displayed_perso, NULL, &pos_perso);
            copyProjectile(ecran, projectile_texture, proj);
            copyEnnemies(ecran, enmi, e, 10);
            copyPlatform(ecran, platform, p, 5);
            SDL_RenderPresent(ecran);
            if (collid(e, &pos_perso, 10))
              reset(&position_f_milieu, &pos_perso, e, &pos_perso_absolue);

            time_now = SDL_GetTicks();
            if (time_now - time_before > tms) //Si la frame est resté suffisamment longtemps, all good
                time_before = time_now;
            else{ // Sinon on temporise avant de passer
                SDL_Delay(tms - (time_now - time_before));
                time_before += tms;
            }
            if (!pause) {
              if (pos_perso_absolue % 1000 == 0) {
                e = tabE(pos_perso_absolue);
                p = tabP(5);
              }
            }

        }
        printf("%d \n",pos_perso_absolue);
        SDL_DestroyTexture(f_milieu);
        SDL_DestroyTexture(perso);
        SDL_DestroyRenderer(ecran);
        freeEnnemy(&e);
        freePlatform(&p);
        highScore("score.txt", pos_perso_absolue);
        // Quitter SDL
        SDL_DestroyWindow(fenetre);



        SDL_Quit();
        return 0;
}
