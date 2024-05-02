#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "defs.h"

struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;

	void logErrorAndExit(const char* msg, const char* error);
	void init();
	void prepareScene(SDL_Texture * background);
    void presentScene();
    SDL_Texture *loadTexture(const char *filename);
    void renderTexture(SDL_Texture *texture, int x, int y);
    void renderPicture(SDL_Texture *texture, int x, int y, int w, int h);
    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
    void quit();
    TTF_Font* loadFont(const char* path, int size);
    SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor);
    Mix_Music *loadMusic(const char* path);
    void play(Mix_Music *gMusic);
    Mix_Chunk* loadSound(const char* path);
    void play(Mix_Chunk* gChunk);
};

#endif // _GRAPHICS__H
