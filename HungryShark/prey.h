#ifndef PREY_H
#define PREY_H

#define PREY_SIZE 10

#include "fish.h"

class Prey : public fish{
public:
    Prey(int x, int y) {
        dx = 0;
        dy = 0;
        speed = 1;
        rect.x = x;
        rect.y = y;
        rect.h = PREY_SIZE;
        rect.w = PREY_SIZE;
    }
};

void render(const Prey& prey, const Graphics& graphics) {
    SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 0, 255); // green
    SDL_RenderFillRect(graphics.renderer, &prey.rect);
}

#endif // PREY_H
