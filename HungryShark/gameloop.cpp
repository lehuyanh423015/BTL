#include "gameloop.h"

void Gameloop::checkExit() {
    while( SDL_PollEvent( &event ) != 0 ) {
        if(event.type == SDL_QUIT ) {
                quit = true;
                continue;
        }
    }
}

void Gameloop::khoiTaoBanDau() {
    Prey temp(0, 0);
    for (int i = 0; i < NUMBERS_PREY; i++) {
        type = 1 + rand() % 4;
        taoPrey(type, temp);
        prey.push_back(temp);
    }
    quit = false;
}

void Gameloop::huongDiChuyen(Shark& shark) {
    if (currentKeyStates[SDL_SCANCODE_UP]) shark.len();
    if (currentKeyStates[SDL_SCANCODE_DOWN]) shark.xuong();
    if (currentKeyStates[SDL_SCANCODE_LEFT]) shark.trai();
    if (currentKeyStates[SDL_SCANCODE_RIGHT]) shark.phai();
}

void Gameloop::hunting(Shark& shark) {
    loop = (loop + 1) % 100;
    for (auto it = prey.begin(); it != prey.end(); ++ it) {
        it->moving();
        if (loop == 0) {
            type = 1 + rand() % 4;
            if (type == 1) it->turnNorth();
            if (type == 2) it->turnSouth();
            if (type == 3) it->turnWest();
            if (type == 4) it->turnEast();
        }
        if (! it->onScreen()) {
            type = 1 + rand() % 4;
            taoPrey(type, *it);
        }
        if (shark.canEat(*it))
        {
            shark.eat(*it);
            type = 1 + rand() % 4;
            taoPrey(type, *it);
        }
        if (shark.canNotEat(*it)) {
            quit = true;
            continue;
        }
    }
    if (shark.canLvUp()) shark.levelUp();
}
