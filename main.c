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
        SDL_Texture* f_milieu = charger_image("fondtriple.bmp", ecran);
        SDL_Rect position_f_milieu = init_fond();
        
        

        SDL_Texture* perso = charger_image("perso.bmp", ecran);
        SDL_Rect pos_perso = init_perso();
        
        int pos_perso_absolue = 0; //avancement du personnage sur la map, indépendant des coordonnées du fond

        int saut = JUMP_TIC; // n'execute pas de base

        int dep_horizontal = 0; //1 si droite, 2 si gauche, 0 sinon

        int time_before = 0;
        int time_now = 0;
        int tms = 1000 / FPS; //Temps (en ms) durant une Frame à l'écran

        ennemy_t *e = tabE();

        SDL_Texture* enmi = charger_image("ennemies.bmp", ecran);
        
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
                    switch(evenements.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                        case SDLK_k:
                            terminer = true;  break;
                        case SDLK_d:
                            dep_horizontal = 1;
                            pos_perso_absolue += 10;

                            break;
                        case SDLK_q:
                            if (pos_perso_absolue > 0) {
                              dep_horizontal = 2;
                              pos_perso_absolue -= 10;
                            }
                            break;
                        case SDLK_SPACE:
                            if (pos_perso.y == 400)
                                saut = 0;
                            break;
                    }


                }


            //Collage des textures
            SDL_RenderCopy(ecran, f_milieu, NULL, &position_f_milieu);
            saut = move(saut, &pos_perso, dep_horizontal, &position_f_milieu, e);
            SDL_RenderCopy(ecran, perso, NULL, &pos_perso);
            copyEnnemies(ecran, enmi, e, 2);
            SDL_RenderPresent(ecran);
            collid(pos_perso_absolue, e, pos_perso);

            dep_horizontal = 0; //On réinitialise le déplacement à chaque tick
            time_now = SDL_GetTicks();
            if (time_now - time_before > tms) //Si la frame est resté suffisamment longtemps, all good
                time_before = time_now;
            else{
                SDL_Delay(tms - (time_now - time_before));
                time_before += tms;
            }

        }
        printf("%d \n",pos_perso_absolue);
        SDL_DestroyTexture(f_milieu);
        SDL_DestroyTexture(perso);
        SDL_DestroyRenderer(ecran);
        highScore("score.txt", pos_perso_absolue);
        // Quitter SDL
        SDL_DestroyWindow(fenetre);



        SDL_Quit();
        return 0;
}
