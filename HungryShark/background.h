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

class Screen {
public:
    Graphics graphics;
    SDL_Texture* background;
    SDL_Texture* pause;

    void khoitao();
    void cbiManHinh();
    void inManHinh();
    void xoaManHinh(Shark& shark);
    void inShark(Shark& shark, int frame);
    void inPrey(Prey& prey);
};

#endif // BACKGROUND_H
