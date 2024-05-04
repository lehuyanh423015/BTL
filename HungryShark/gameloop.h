#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <bits/stdc++.h>

#include "shark.h"
#include "prey.h"
#include "defs.h"
#include "graphics.h"
#include "sound.h"
#include "background.h"

using namespace std;

class Gameloop {
private:
    int type;
    int loop;
    const Uint8* currentKeyStates;

public:
    Sound sound;
    vector <Prey> prey;
    Gameloop() : currentKeyStates(SDL_GetKeyboardState(NULL)), quit(false) {}

    bool quit;
    bool died;

    void init_prey();

    void shark_moving(Shark& shark);
    void shark_hunting(Shark& shark);
};

#endif // GAMELOOP_H
