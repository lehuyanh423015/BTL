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
#include "sprite.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));
    Screen scr;
    scr.khoitao();
    Gameloop game;
    int frame = -1;
    Shark shark(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    shark.khoitao(scr.graphics);

    game.khoiTaoBanDau();
    while(!game.quit) {
        frame = (frame + 1) % 10;
        scr.cbiManHinh();
        game.checkExit();
        game.huongDiChuyen(shark);
        game.conMoiDiChuyen();
        game.caMapDiSan(shark);
        scr.inShark(shark, frame);
        for (int i = 0; i < NUMBERS_PREY; i++) scr.inPrey(game.prey[i]);
        scr.inManHinh();
    }

    scr.xoaManHinh(shark);
    return 0;
}
