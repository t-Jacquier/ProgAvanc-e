#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonction_SDL.h"
#include <SDL2/SDL_ttf.h>

int main(int argc, char *argv[]){
    SDL_Window* fenetre;  // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
    bool terminer = false;
    if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());SDL_Quit();return EXIT_FAILURE;}// Créer la fenêtre
        fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
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
        SDL_Texture* f_milieu = charger_image("fond.bmp", ecran);
        int pos_fond = 0;
        SDL_Rect position_f_milieu;
        position_f_milieu.x = pos_fond;
        position_f_milieu.y = 0;
        position_f_milieu.h = 600;
        position_f_milieu.w = 600;
        
        //Image qui apparait à l'avancement
        SDL_Texture* f_avant = charger_image("fond.bmp", ecran);
        int pos_fond_avant = pos_fond + 600;
        SDL_Rect position_f_avant;
        position_f_avant.x = pos_fond_avant;
        position_f_avant.y = 0;
        position_f_avant.h = 600;
        position_f_avant.w = 600;
        
        
        //Image qui apparait au reculement
        SDL_Texture* f_arriere = charger_image("fond.bmp", ecran);
        int pos_fond_arriere = pos_fond - 600;
        SDL_Rect position_f_arriere;
        position_f_arriere.x = pos_fond_arriere;
        position_f_arriere.y = 0;
        position_f_arriere.h = 600;
        position_f_arriere.w = 600;
        
        SDL_Texture* perso = charger_image("perso.bmp", ecran);
        SDL_Rect pos_perso;
        pos_perso.x = 280;
        pos_perso.y = 400;
        pos_perso.h = 80;
        pos_perso.w = 40;
        
        
        // Boucle principale
        while(!terminer)
        {
            
            SDL_RenderClear(ecran);
            
            //Actualisation des positions du fond
            position_f_milieu.x = pos_fond;
            position_f_avant.x = pos_fond_avant;
            position_f_arriere.x = pos_fond_arriere;
            
            //Collage des textures
            SDL_RenderCopy(ecran, f_milieu, NULL, &position_f_milieu);
            SDL_RenderCopy(ecran, f_avant, NULL, &position_f_avant);
            SDL_RenderCopy(ecran, f_arriere, NULL, &position_f_arriere);
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
                        case SDLK_k:
                            terminer = true;  break;
                        case SDLK_d:
                            pos_fond -= 10;
                            if (pos_fond == -600) //Si on arrive à gauche
                                pos_fond = 0; //On replace l'image du milieu
                            pos_fond_avant = pos_fond + 600;
                            pos_fond_arriere = pos_fond - 600;
                            break;
                        case SDLK_q:
                            pos_fond += 10; 
                            if (pos_fond == 600) //Si on arrive à droite
                                pos_fond = 0; //On replace l'image du milieu 
                            pos_fond_avant = pos_fond + 600;
                            pos_fond_arriere = pos_fond - 600; break;
                                
                    }
                }
           SDL_RenderPresent(ecran); 
        }
        
        SDL_DestroyTexture(f_milieu);
        SDL_DestroyTexture(f_avant);
        SDL_DestroyTexture(f_arriere);
        SDL_DestroyTexture(perso);
        SDL_DestroyRenderer(ecran);
        // Quitter SDL
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        return 0;
}
