#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "graphics.h"
#include "defs.h"
#include "fish.h"
#include "shark.h"
#include "prey.h"
#include "background.h"
#include "gameloop.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));
    Screen scr;
    scr.khoitao();
    Gameloop game;
    Shark shark(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    game.khoiTaoBanDau();
    while(!game.quit) {
        scr.cbiManHinh();
        game.checkExit();
        game.huongDiChuyen(shark);
        game.conMoiDiChuyen();
        game.caMapDiSan(shark);
        scr.inShark(shark);
        for (int i = 0; i < NUMBERS_PREY; i++) scr.inPrey(game.prey[i]);
        scr.inManHinh();
    }

    scr.xoaManHinh();
    return 0;
}
