#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <vector>
#include <SDL.h>
#include <SDL_image.h>

#include "shark.h"
#include "prey.h"
#include "defs.h"
#include "graphics.h"

using namespace std;

class Gameloop {
private:
    int type;
    int loop;
    const Uint8* currentKeyStates;
    SDL_Event event;

public:
    vector <Prey> prey;
    Gameloop() : currentKeyStates(SDL_GetKeyboardState(NULL)), quit(false) {}
    bool quit;

    void checkExit();
    void khoiTaoBanDau();
    void huongDiChuyen(Shark& shark);
    void conMoiDiChuyen();
    void caMapDiSan(Shark& shark);
};

#endif // GAMELOOP_H
