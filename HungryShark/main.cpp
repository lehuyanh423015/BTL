#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "graphics.h"
#include "defs.h"
#include "fish.h"
#include "shark.h"
#include "prey.h"
#include "background.h"
#include "gameloop.h"
#include "sprite.h"
#include "font.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

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

    scr.menugame();
    scr.inManHinh();
    waitUntilKeyPressed();

    while(!game.quit) {
        frame = (frame + 1) % 10;
        scr.cbiManHinh();
        game.checkExit();
        game.huongDiChuyen(shark);
        game.hunting(shark);
        scr.inShark(shark, frame);
        for (auto it = game.prey.begin(); it != game.prey.end(); ++ it)
            scr.inPrey(*it);
        scr.inManHinh();
    }

    scr.xoaManHinh(shark);
    return 0;
}
