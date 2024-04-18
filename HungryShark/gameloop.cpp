#include "gameloop.h"

void Gameloop::checkExit() {
    while( SDL_PollEvent( &event ) != 0 ) {
        if(event.type == SDL_QUIT ) quit = true;
    }
}

void Gameloop::khoiTaoBanDau() {
    for (int i = 0; i < NUMBERS_PREY; i++) {
        type = 1 + rand() % 4;
        Prey temp(0, 0);
        taoPrey(type, temp);
        prey.push_back(temp);
    }
    quit = false;
    loop = 1;
}

void Gameloop::huongDiChuyen(Shark& shark) {
    if (currentKeyStates[SDL_SCANCODE_UP]) shark.len();
    if (currentKeyStates[SDL_SCANCODE_DOWN]) shark.xuong();
    if (currentKeyStates[SDL_SCANCODE_LEFT]) shark.trai();
    if (currentKeyStates[SDL_SCANCODE_RIGHT]) shark.phai();
}

void Gameloop::conMoiDiChuyen() {
    for (int i = 0; i < NUMBERS_PREY; i++) {
        prey[i].moving();
    }
    loop = (loop + 1) % 100;
    if (loop == 0)
    {
        for (int i = 0; i < NUMBERS_PREY; i++)
        {
            type = 1 + rand() % 4;
            if (type == 1) prey[i].turnNorth();
            if (type == 2) prey[i].turnSouth();
            if (type == 3) prey[i].turnWest();
            if (type == 4) prey[i].turnEast();
            if (! prey[i].onScreen()) {
                prey.erase(prey.begin() + i);
                Prey temp(0, 0);
                taoPrey(type, temp);
                prey.push_back(temp);
            }
        }
    }
}

void Gameloop::caMapDiSan(Shark& shark) {
    for (int i = 0; i < NUMBERS_PREY; i++)
    {
        if (shark.canEat(prey[i]))
        {
            shark.eat(prey[i]);
            loop = 1;
            prey.erase(prey.begin() + i);
            type = 1 + rand() % 4;
            Prey temp(0, 0);
            taoPrey(type, temp);
            prey.push_back(temp);
        }
        if (shark.canNotEat(prey[i])) {
            quit = true;
        }
    }
    if (shark.canLvUp()) shark.levelUp();
}
