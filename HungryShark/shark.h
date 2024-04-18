#ifndef SHARK_H
#define SHARK_H

#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"
#include "fish.h"
#include "defs.h"
#include "prey.h"

class Shark : public Fish {
public:
    Shark(int x, int y) {
        dx = 0;
        dy = 0;
        speed = 2;
        level = 1;
        exp = 0;
        rect.x = x;
        rect.y = y;
        rect.h = level * 10;
        rect.w = level * 10;
    }
    bool onScreen();
    bool canEat(const Prey& prey);
    bool canNotEat(const Prey& prey);
    bool canLvUp();

    void eat(const Prey& prey);
    void levelUp();
    void render(const Graphics& graphics);
    void len();
    void xuong();
    void trai();
    void phai();
};

#endif // SHARK_H
