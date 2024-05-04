#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "graphics.h"
#include "defs.h"
#include "fish.h"
#include "shark.h"
#include "prey.h"
#include "background.h"
#include "gameloop.h"
#include "sprite.h"
#include "font.h"

using namespace std;

bool play_game(int x, int y) {
    return x >= 500 && y >= 255 && x <= 770 && y <= 355;
}

bool quit_game(int x, int y) {
    return x >= 500 && y >= 380 && x <= 770 && y <= 480;
}

bool pause_game(int x, int y) {
    return x >= 10 && y >= 10 && x <= 50 && y <= 50;
}

bool to_menu(int x, int y) {
    return x >= 440 && y >= 330 && x <= 500 && y <= 390;
}

bool to_resume(int x, int y) {
    return x >= 355 && y >= 330 && x <= 415 && y <= 390;
}

bool to_restart(int x, int y) {
    return x >= 550 && y >= 330 && x <= 610 && y <= 390;
}

bool end_restart(int x, int y) {
    return x >= 240 && y >= 360 && x <= 455 && y <= 410;
}

bool end_home(int x, int y) {
    return x >= 510 && y >= 360 && x <= 720 && y <= 410;
}

int main(int argc, char *argv[])
{
    srand(time(0));
    Screen scr;

    scr.init_grap_music();

    int x, y;
    bool back_menu = false;
    SDL_Event event;
    scr.init_menu();

    do {
        scr.render_menu();
        back_menu = true;
        SDL_GetMouseState(&x, &y);
        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT) exit(0);

        if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (play_game(x, y)) {
                Gameloop game;
                bool restart = false;
                do {
                    restart = false;
                    int frame = -1;
                    Shark shark(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

                    scr.init_gameplay();
                    game.init_prey();
                    shark.init_shark(scr.graphics);

                    while(! game.quit) {
                        frame = (frame + 1) % 10;

                        game.shark_moving(shark);
                        game.shark_hunting(shark);

                        scr.render_gameplay();
                        scr.render_shark(shark, frame);
                        for (int i = 0; i < 10; i++) scr.render_prey(game.prey[i]);

                        scr.graphics.presentScene();

                        if (game.died) {
                            scr.init_died();
                            scr.render_died();
                            scr.graphics.presentScene();

                            scr.xoa_gamePlay();
                            scr.xoa_pause();
                            shark.xoa_shark();

                            bool resume = false;

                            while (! resume) {
                                SDL_GetMouseState(&x, &y);
                                SDL_PollEvent(&event);

                                if (event.type == SDL_QUIT) exit(0);

                                if (event.type == SDL_MOUSEBUTTONDOWN) {
                                    if (end_home(x, y)) {
                                        scr.xoa_died();

                                        restart = false;
                                        resume = true;
                                        game.quit = true;
                                        break;
                                    }

                                    if (end_restart(x, y)) {
                                        scr.xoa_died();

                                        restart = true;
                                        resume = true;
                                        game.quit = true;

                                        break;
                                    }
                                }
                            }
                        }


                        SDL_GetMouseState(&x, &y);
                        SDL_PollEvent(&event);

                        if (event.type == SDL_QUIT) exit(0);

                        if (event.type == SDL_MOUSEBUTTONDOWN && pause_game(x, y)) {
                            bool resume = false;
                            scr.init_pause();
                            scr.render_pause();
                            scr.graphics.presentScene();

                            while (! resume) {
                                SDL_GetMouseState(&x, &y);
                                SDL_PollEvent(&event);

                                if (event.type == SDL_MOUSEBUTTONDOWN) {
                                    if (to_resume(x, y)) {
                                        resume = true;
                                        scr.xoa_pause();
                                        break;
                                    }

                                    if (to_restart(x, y)) {
                                        scr.xoa_gamePlay();
                                        scr.xoa_pause();
                                        shark.xoa_shark();

                                        restart = true;
                                        resume = true;
                                        game.quit = true;

                                        break;
                                    }
                                    if (to_menu(x, y)) {
                                        scr.xoa_gamePlay();
                                        scr.xoa_pause();
                                        shark.xoa_shark();

                                        restart = false;
                                        resume = true;
                                        game.quit = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                while (restart);
            }
            else if(quit_game(x, y)) exit(0);
        }
    }
    while (back_menu);
    scr.graphics.quit();
    return 0;
}
