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
        
        SDL_Texture* fond = charger_image("fond.bmp", ecran);
        int pos = 0;
        SDL_Rect position_fond;
        position_fond.x = pos;
        position_fond.y = 0;
        position_fond.h = 600;
        position_fond.w = 600;
        
        SDL_Texture* fondbis = charger_image("fond.bmp", ecran);
        int posbis = pos + 600;
        SDL_Rect position_fondbis;
        position_fondbis.x = pos;
        position_fondbis.y = 0;
        position_fondbis.h = 600;
        position_fondbis.w = 600;
        
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
            position_fond.x = pos;
            position_fondbis.x = posbis;
            SDL_RenderCopy(ecran, fond, NULL, &position_fond);
            SDL_RenderCopy(ecran, fondbis, NULL, &position_fondbis);
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
                        case SDLK_q:
                            terminer = true;  break;
                        case SDLK_d:
                            pos -= 10;
                            if (pos == -600)
                                pos = 0;
                            posbis = pos + 600;
                                
                    }
                }
           SDL_RenderPresent(ecran); 
        }
        
        SDL_DestroyTexture(fond);
        SDL_DestroyRenderer(ecran);
        // Quitter SDL
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
        return 0;
}
