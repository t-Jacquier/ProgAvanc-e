#include "fonction_SDL.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

/**
 * @brief Représente une plateforme
 */
struct s_platform{
    SDL_Rect coo; 
    bool visible; 
};

typedef struct s_platform platform_t;

/**
  * @brief Initialise une platforme
  * @param x Position sur l'axe des abscisses
  * @param y Position sur l'axe des ordonnées
  * @param w Largeur du sprite
  * @param h Hauteur du sprite
  * @param est_visible Visible ou non 
  * @return Plateforme initialisée
  */
platform_t initP(int x, int y, int w, int h, bool est_visible);

/**
 * @brief Initialise un tableau de plateformes
 * @param nb_platform Taille du tableau
 * @return Tableau de plateformes placées à des positions aléatoires
 */
platform_t* tabP(int nb_platform);

/**
 * @brief Libère la mémoire du tableau passé
 * @param p[] Tableau de plateformes
 */
void freePlatform(platform_t* p[]);

/**
 * @brief Affiche un tableau de plateformes
 * @param screen Renderer où afficher
 * @param text Texture des plateformes
 * @param tab Tableau à afficher
 * @param nb_platform Nombre de plateformes à afficher
*/
void copyPlatform(SDL_Renderer* screen, SDL_Texture* text, platform_t tab[], int nb_platform);

/**
 * @brief Décale un tableau de plateformes par rapport aux mouvements à droite du personnage
 * @param p Tableau de plateformes
 * @param nb_platform Nombre de plateformes à déplacer 
 */
void movePlatformRight(platform_t* p, int nb_platform);

/**
 * @brief Décale un tableau de plateformes par rapport aux mouvements à gauche du personnage
 * @param en tableau de plateformes
 * @param nbEnnemies Nombre de plateformes à déplacer 
 */
void movePlatformLeft(platform_t* en, int nb_platform);

/**
 * @brief détecte la collision entre le personnage et une plateforme
 * @param p plateforme à tester
 * @param struct_perso Ensemble de coordonnées du personnage
 * @return TRUE si collision FALSE sinon
 */
int detectCollid_platform(platform_t *p, SDL_Rect* struct_perso);
