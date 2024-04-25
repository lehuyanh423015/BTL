#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    Sprite fright;
    Sprite fleft;
    Sprite fup;
    Sprite fdown;

    SDL_Texture* frightTexture = graphics.loadTexture(FISH_RIGHT);
    fright.init(frightTexture, FRAMES, RIGHT_CLIPS);

    SDL_Texture* fleftTexture = graphics.loadTexture(FISH_LEFT);
    fleft.init(fleftTexture, FRAMES, LEFT_CLIPS);

    SDL_Texture* fupTexture = graphics.loadTexture(FISH_UP);
    fup.init(fupTexture, FRAMES, UP_CLIPS);

    SDL_Texture* fdownTexture = graphics.loadTexture(FISH_DOWN);
    fdown.init(fdownTexture, FRAMES, DOWN_CLIPS);

    bool quit = false;
    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = true;
        }
        fright.tick();
        fleft.tick();
        fup.tick();
        fdown.tick();

        graphics.prepareScene();
        graphics.render(150, 100, fright);
        graphics.render(150, 200, fleft);
        graphics.render(150, 300, fup);
        graphics.render(150, 400, fdown);
        graphics.presentScene();
        SDL_Delay(200);
    }

	SDL_DestroyTexture( frightTexture ); frightTexture = nullptr;
	SDL_DestroyTexture( fleftTexture ); fleftTexture = nullptr;
	SDL_DestroyTexture( fupTexture ); fupTexture = nullptr;
	SDL_DestroyTexture( fdownTexture ); fdownTexture = nullptr;

    graphics.quit();
    return 0;
}
