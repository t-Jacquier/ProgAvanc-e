#include <SDL2/SDL.h>

/**
 * @brief Charge une texture
 * @param nomfichier nom de l'image à charger
 * @param renderer Rendu où s'affichera la texture
 * @return Texture contenant l'image chargée
 */
SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*
renderer);

/**
 * @brief charge une texture en passant en transparence une couleur
 * @param nomfichier nom de l'image à charger
 * @param renderer rendu où s'affichera la texture
 * @param r quantité de rouge
 * @param g quantité de vert
 * @param b quantité de bleue
 * @return
 */
SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b); 

// SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer,TTF_Font *font, SDL_Color color);
