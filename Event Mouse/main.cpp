#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"

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
    Graphics graphics;
    graphics.init();

    SDL_Event event;
    int x, y;
    SDL_Texture *targetterTexture = graphics.loadTexture("img\\Spongebob.png");
    while (true)
    {
        SDL_PollEvent(&event);
        SDL_GetMouseState(&x, &y);
        graphics.renderTexture(targetterTexture, x, y);
        graphics.presentScene();
        graphics.clearScrene();
        switch (event.type)
        {
            case SDL_QUIT:
                 exit(0);
                 break;
        }
        SDL_Delay(0);
    }

    graphics.quit();
    return 0;

}
