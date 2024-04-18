#ifndef FISH_H
#define FISH_H

#include <SDL.h>
#include <SDL_image.h>

#include "defs.h"

class Fish {
public:
    int level, exp;
    int dx, dy;
    int speed;
    SDL_Rect rect;

    void turnNorth();
    void turnSouth();
    void turnWest();
    void turnEast();
    void moving();
};

#endif // FISH_H
