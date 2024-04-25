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
public:
    Sprite fright;
    Sprite fleft;
    Sprite fup;
    Sprite fdown;
    Sprite sprite;

    SDL_Texture* frightTexture;
    SDL_Texture* fleftTexture;
    SDL_Texture* fupTexture;
    SDL_Texture* fdownTexture;

    Shark(int x, int y) {
        dx = 0;
        dy = 0;
        speed = 3;
        level = 1;
        exp = 0;
        rect.x = x;
        rect.y = y;
        rect.h = level * 36;
        rect.w = level * 36;
    }
    void khoitao(Graphics& graphics);
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
