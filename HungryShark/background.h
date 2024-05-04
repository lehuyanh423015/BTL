#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>

#include "graphics.h"
#include "defs.h"
#include "shark.h"
#include "prey.h"
#include "font.h"
#include "sound.h"

class Screen {
private:
    SDL_Texture* background;
    SDL_Texture* pause;
    SDL_Texture* menu;
    SDL_Texture* gPause;
    SDL_Texture* died;
    Sound sound;

public:
    Graphics graphics;

    void init_grap_music();

    void init_menu();
    void render_menu();
    void xoa_menu();

    void init_gameplay();
    void render_gameplay();
    void xoa_gamePlay();

    void init_pause();
    void render_pause();
    void xoa_pause();

    void init_died();
    void render_died();
    void xoa_died();

    void render_shark(Shark& shark, int frame);

    void render_prey(Prey& prey);
};

#endif // BACKGROUND_H
