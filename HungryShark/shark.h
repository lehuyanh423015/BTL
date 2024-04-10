#ifndef SHARK_H
#define SHARK_H

#define INITIAL_SPEED 2
#define SHARK_SIZE 30

#include "fish.h"
#include "prey.h"

bool inside(int x, int y, SDL_Rect r) {
    return x > r.x && x < r.x+r.w && y > r.y && y < r.y+r.h;
}

bool overlap(const SDL_Rect& r1, const SDL_Rect& r2) {
    return inside(r1.x, r1.y, r2) || inside(r1.x + r1.w, r1.y, r2) ||
            inside(r1.x, r1.y+r1.h, r2) || inside(r1.x+r1.w, r1.y+r1.h, r2);
}

class Shark : public fish{
public:
    Shark(int x, int y) : fish() {
        dx = 0;
        dy = 0;
        speed = INITIAL_SPEED;
        rect.x = x;
        rect.y = y;
        rect.h = SHARK_SIZE;
        rect.w = SHARK_SIZE;
    }

    bool canEat(const Prey& prey) {
        return overlap(rect, prey.rect);
    }

    void grow() {
        rect.h += 1;
        rect.w += 1;
    }
};

void render(const Shark& shark, const Graphics& graphics) {
    SDL_SetRenderDrawColor(graphics.renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(graphics.renderer, &shark.rect);
}

bool gameOver(const Shark& shark) {
    return shark.rect.x < 0 || shark.rect.x + shark.rect.w >= SCREEN_WIDTH ||
           shark.rect.y < 0 || shark.rect.y + shark.rect.h >= SCREEN_HEIGHT;
}

#endif // SHARK_H
