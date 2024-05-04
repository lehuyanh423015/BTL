#ifndef SHARK_H
#define SHARK_H

#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"
#include "fish.h"
#include "defs.h"
#include "prey.h"
#include "sprite.h"

class Shark : public Fish {
private:
    Sprite fright;
    Sprite fleft;
    Sprite fup;
    Sprite fdown;

    SDL_Texture* frightTexture;
    SDL_Texture* fleftTexture;
    SDL_Texture* fupTexture;
    SDL_Texture* fdownTexture;

public:
    Sprite sprite;
    Shark(int x, int y) {
        dx = 0;
        dy = 0;
        speed = 3;
        level = 2;
        exp = 0;
        rect.x = x;
        rect.y = y;
        rect.h = level * 18;
        rect.w = level * 18;
    }

    void init_shark(Graphics& graphics);
    void render_shark(Graphics& graphics);
    void xoa_shark();

    bool onScreen();

    bool canEat(const Prey& prey);
    bool canNotEat(const Prey& prey);
    void eat(const Prey& prey);

    bool canLvUp();
    void levelUp();

    void len();
    void xuong();
    void trai();
    void phai();
};
#endif // SHARK_H
