#ifndef FONT_H
#define FONT_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

#include "defs.h"
#include "graphics.h"

using namespace std;

class Font {
public:
    int font_size;
    const char* font_text;
    SDL_Texture* Text;
    SDL_Color color;
    TTF_Font* font;

    Font(const char* text, int sz) {
        font_text = text;
        font_size = sz;
    }

    void renderText(int x, int y, Graphics& graphics);
};

#endif // FONT_H
