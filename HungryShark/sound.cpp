#include "sound.h"

void Sound::nhacNen() {
    gMusic = loadMusic(MUSIC);
    play(gMusic);
}

void Sound::nhac_bite() {
    Mix_Chunk *gBite = loadSound(BITE_WAV);
    play(gBite);

    double first = SDL_GetTicks();
    double last = 0;
    if (first - last == 1000) {
        if (gBite != nullptr) Mix_FreeChunk( gBite);
    }
}

void Sound::end_game()
{
    if (gMusic != nullptr) Mix_FreeMusic( gMusic );
    gEnd = loadMusic(END_GAME);
    play(gEnd);
}
