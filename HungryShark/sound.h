#ifndef SOUND_H
#define SOUND_H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_mixer.h>

#include "defs.h"
#include "graphics.h"

class Sound : public Graphics{
private:
    Mix_Music *gMusic;
    Mix_Music *gEnd;

public:
    void nhacNen();
    void nhac_bite();
};

#endif // SOUND_H
