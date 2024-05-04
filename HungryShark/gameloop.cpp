#include "gameloop.h"

void Gameloop::init_prey() {
    prey.clear();
    Prey temp(0, 0);
    for (int i = 0; i < 10; i++) {
        type = 1 + rand() % 4;
        taoPrey(type, temp);
        prey.push_back(temp);
    }
    quit = false;
    died = false;
}

void Gameloop::shark_moving(Shark& shark) {
    if (currentKeyStates[SDL_SCANCODE_UP]) shark.len();
    if (currentKeyStates[SDL_SCANCODE_DOWN]) shark.xuong();
    if (currentKeyStates[SDL_SCANCODE_LEFT]) shark.trai();
    if (currentKeyStates[SDL_SCANCODE_RIGHT]) shark.phai();
}

void Gameloop::shark_hunting(Shark& shark) {
    loop = (loop + 1) % 100;
    for (int i = 0; i < 10; i++) {
        prey[i].moving();
        if (loop == 0) {
            type = 1 + rand() % 4;
            if (type == 1) prey[i].turnNorth();
            if (type == 2) prey[i].turnSouth();
            if (type == 3) prey[i].turnWest();
            if (type == 4) prey[i].turnEast();
        }
        if (! prey[i].onScreen()) {
            type = 1 + rand() % 4;
            taoPrey(type, prey[i]);
        }
        if (shark.canEat(prey[i]))
        {
            sound.nhac_bite();
            shark.eat(prey[i]);
            type = 1 + rand() % 4;
            taoPrey(type, prey[i]);
        }
        if (shark.canNotEat(prey[i])) {
            died = true;
        }
    }
    if (shark.canLvUp()) shark.levelUp();
}
