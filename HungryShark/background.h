#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"
#include "defs.h"
#include "shark.h"
#include "prey.h"

class Screen {
private:
    Graphics graphics;
    SDL_Texture* background;

public:
    void khoitao();
    void cbiManHinh();
    void inManHinh();
    void xoaManHinh();
    void inShark(Shark& shark);
    void inPrey(Prey& prey);
};

#endif // BACKGROUND_H
