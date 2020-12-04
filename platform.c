#include "fonction_SDL.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"
#include "platform.h"

platform_t initP(int x, int y, int w, int h, bool est_visible){
    platform_t platform;
    platform.coo.x = x;
    platform.coo.y = y;
    platform.coo.w = w;
    platform.coo.h = h;
    platform.visible = est_visible;
    
    return platform;
}

    
