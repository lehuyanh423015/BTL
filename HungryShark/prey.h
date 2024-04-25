#ifndef PREY_H
#define PREY_H

#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"
#include "fish.h"
#include "defs.h"

class Prey : public Fish {
public:
    Prey(int x, int y) {
        dx = 0;
        dy = 0;
        speed = 1;
        level = 1 + rand() % 7;
        exp = level * 10;
        rect.x = x;
        rect.y = y;
        rect.h = level * 10;
        rect.w = level * 10;
    }

    bool onScreen();

    void render(const Graphics& graphics) const;
};

inline void taoPrey(int type, Prey& prey) {
    int x, y;
    if (type == 1) {
        x = -50;
        y = rand() % SCREEN_HEIGHT;
        prey = Prey(x, y);
        prey.turnEast();
    }
    if (type == 2) {
        x = rand() % SCREEN_WIDTH;
        y = -50;
        prey = Prey(x, y);
        prey.turnSouth();
    }
    if (type == 3) {
        x = SCREEN_WIDTH;
        y = rand() % SCREEN_HEIGHT;
        prey = Prey(x, y);
        prey.turnWest();
    }
    if (type == 4) {
        x = rand() % SCREEN_WIDTH;
        y = SCREEN_HEIGHT;
        prey = Prey(x, y);
        prey.turnNorth();
    }
}

#endif // PREY_H
