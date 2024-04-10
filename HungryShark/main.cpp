#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "graphics.h"
#include "defs.h"
#include "fish.h"
#include "shark.h"
#include "prey.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(0));
    int loop = 0;
    Graphics graphics;
    graphics.init();

    SDL_Texture* background = graphics.loadTexture(BACKGROUND_IMG);
    SDL_Texture* myshark = graphics.loadTexture(MYSHARK);

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
        graphics.prepareScene(background);

        while( SDL_PollEvent( &event ) != 0 ) {
            if(event.type == SDL_QUIT ) quit = true;
        }
        SDL_RenderCopy(graphics.renderer, background, NULL, NULL);
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if (currentKeyStates[SDL_SCANCODE_W])
        {
            shark.turnNorth();
            shark.moving();
        }
        if (currentKeyStates[SDL_SCANCODE_S])
        {
            shark.turnSouth();
            shark.moving();
        }
        if (currentKeyStates[SDL_SCANCODE_A])
        {
            shark.turnWest();
            shark.moving();
        }
        if (currentKeyStates[SDL_SCANCODE_D])
        {
            shark.turnEast();
            shark.moving();
        }
        if (currentKeyStates[SDL_SCANCODE_UP]) shark.speep_up();
        if (currentKeyStates[SDL_SCANCODE_DOWN]) shark.speep_dn();


        for (int i = 0; i < 10; i++) fishs[i].moving();
        loop = (loop + 1) % 100;
        if (loop == 1)
        {
            int* type = new int;
            for (int i = 0; i < 10; i++)
            {
                *type = 1 + rand() % 4;
                if (*type == 1) fishs[i].turnNorth();
                if (*type == 2) fishs[i].turnSouth();
                if (*type == 3) fishs[i].turnWest();
                if (*type == 4) fishs[i].turnEast();
            }
            delete type;
        }
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

    SDL_DestroyTexture( background );
    SDL_DestroyTexture(myshark);
    graphics.quit();
    return 0;
}
