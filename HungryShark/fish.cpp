#include "fish.h"

void Fish::turnNorth() {
    dy = -speed;
    dx = 0;
}

void Fish::turnSouth() {
    dy = speed;
    dx = 0;
}

void Fish::turnWest() {
    dy = 0;
    dx = -speed;
}

void Fish::turnEast() {
    dy = 0;
    dx = speed;
}

void Fish::moving() {
    rect.x += dx;
    rect.y += dy;
}
