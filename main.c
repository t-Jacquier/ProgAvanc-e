#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
#include "fonction_SDL.h"
#include <SDL2/SDL_ttf.h>

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
        if (fenetre==NULL){ // test
            printf("Erreur de la creation du rendu : %s" ,SDL_GetError());
            SDL_Quit();
            return EXIT_FAILURE;
        }
        
        //Image centrale
        SDL_Texture* f_milieu = charger_image("fondtriple.bmp", ecran);
        if(f_milieu==NULL){ //test
            printf("Erreur de la creation de la texture : %s" ,SDL_GetError());
            SDL_Quit();
            return EXIT_FAILURE; 
        }
        
        int pos_fond = -600;
        SDL_Rect position_f_milieu;
        position_f_milieu.x = pos_fond;
        position_f_milieu.y = 0;
        position_f_milieu.h = 600;
        position_f_milieu.w = 1800;
        
        
        
        
        //Personnage
        SDL_Texture* perso = charger_image("perso.bmp", ecran);
        if(perso==NULL){ //test
            printf("Erreur de la creation de la texture : %s" ,SDL_GetError());
            SDL_Quit();
            return EXIT_FAILURE; 
        }
        
        SDL_Rect pos_perso;
        pos_perso.x = 280;
        pos_perso.y = 400;
        pos_perso.h = 80;
        pos_perso.w = 40;
        
        int pos_perso_absolue = 0; //avancement du personnage sur la map, indépendant des coordonnées du fond
        
        
        
        
        // Boucle principale
        while(!terminer)
        {
            
            SDL_RenderClear(ecran);
            
            //Actualisation des positions du fond
            position_f_milieu.x = pos_fond;
            
            //Collage des textures
            SDL_RenderCopy(ecran, f_milieu, NULL, &position_f_milieu);
            SDL_RenderCopy(ecran, perso, NULL, &pos_perso);
            
            while (SDL_PollEvent( &evenements ) )
                switch(evenements.type)
                {
                    case SDL_QUIT:
                        terminer = true; break;
                    case SDL_KEYDOWN:
                    switch(evenements.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            terminer = true; break; 
                        case SDLK_k:
                            terminer = true;  break;
                        case SDLK_d:
                            pos_fond -= 10;
                            pos_perso_absolue += 10;
                            if (pos_fond == -1200) //Si on arrive à gauche
                                pos_fond = -600; //On replace l'image du milieu
                            break;
                        case SDLK_q:
                            pos_fond += 10;
                            pos_perso_absolue -= 10;
                            if (pos_fond == 0) //Si on arrive à droite
                                pos_fond = -600; //On replace l'image du milieu 
                                
                    }
                }  
                
           
           
           
        
           SDL_RenderPresent(ecran); 
        }
        printf("%d \n",pos_perso_absolue);
        SDL_DestroyTexture(f_milieu);
        SDL_DestroyTexture(perso);
        SDL_DestroyRenderer(ecran);
        // Quitter SDL
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        return 0;
}
