#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "graphics.h"

using namespace std;

class Sprite {
public:
    SDL_Texture* texture;
    vector<SDL_Rect> clips;
    int currentFrame = 0;

    void init(SDL_Texture* _texture, int frames, const int _clips [][4]);
    void tick();
    const SDL_Rect* getCurrentClip() const;
};

#endif // SPRITE_H
