#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "graphics.h"
#include "defs.h"
#include "shark.h"
//#include "AI_prey.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));
    Graphics graphics;
    graphics.init();

    ScrollingBackground background;
    background.setTexture(graphics.loadTexture(BACKGROUND_IMG));

    Shark shark(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    vector <Prey> fishs;
    for (int i = 0; i < 10; i++)
    {
        int x = rand() % SCREEN_WIDTH;
        int y = rand() % SCREEN_HEIGHT;
        Prey prey(x, y);
        fishs.push_back(prey);
    }

    bool quit = false;
    SDL_Event event;
    while(!quit && !gameOver(shark)) {
        graphics.prepareScene();

        while( SDL_PollEvent( &event ) != 0 ) {
            if(event.type == SDL_QUIT ) quit = true;
        }

        background.scroll(1);

        graphics.render(background);

        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (currentKeyStates[SDL_SCANCODE_UP]) shark.turnNorth();
        if (currentKeyStates[SDL_SCANCODE_DOWN]) shark.turnSouth();
        if (currentKeyStates[SDL_SCANCODE_LEFT]) shark.turnWest();
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) shark.turnEast();

        shark.moving();

        for (int i = 0; i < 10; i++)
        {
            if (shark.canEat(fishs[i]))
            {
                shark.grow();
                int x = rand() % SCREEN_WIDTH;
                int y = rand() % SCREEN_HEIGHT;
                fishs.erase(fishs.begin() + i);
                Prey prey(x, y);
                fishs.push_back(prey);
            }
        }
        render(shark, graphics);
        for (int i = 0; i < 10; i++) render(fishs[i], graphics);

        graphics.presentScene();
    }

    SDL_DestroyTexture( background.texture );
    graphics.quit();
    return 0;
}
