#include "shark.h"
#include "prey.h"

bool inside(int x, int y, SDL_Rect r) {
    return x >= r.x
        && x <= r.x+r.w
        && y >= r.y
        && y <= r.y+r.h;
}

bool overlap(const SDL_Rect& r1, const SDL_Rect& r2) {
    return inside(r1.x, r1.y, r2)
        || inside(r1.x + r1.w, r1.y, r2)
        || inside(r1.x, r1.y+r1.h, r2)
        || inside(r1.x+r1.w, r1.y+r1.h, r2);
}

bool Shark::onScreen() {
    return rect.x >= 0
        && rect.y >= 0
        && rect.x + rect.w <= SCREEN_WIDTH
        && rect.y + rect.h <= SCREEN_HEIGHT;
}

bool Shark::canEat(const Prey& prey) {
    return overlap(prey.rect, rect) && level >= prey.level;
}

bool Shark::canNotEat(const Prey& prey) {
    return overlap(prey.rect, rect) && level < prey.level;
}

bool Shark::canLvUp() {
    return exp >= level * 100;
}


void Shark::eat(const Prey& prey) {
    exp += prey.exp;
}

void Shark::levelUp() {
    exp = exp % (level * 100);
    level += 1;
    if (level > 6) level = 6;
    rect.h = level * 10;
    rect.w = level * 10;
}

void Shark::render(const Graphics& graphics) {
    SDL_SetRenderDrawColor(graphics.renderer, 125, 180, 150, 135);
    SDL_RenderFillRect(graphics.renderer, &rect);
}

void Shark::len() {
    turnNorth();
    moving();
    if (! onScreen()) {
        turnSouth();
        moving();
    }
}

void Shark::xuong() {
    turnSouth();
    moving();
    if (! onScreen()) {
        turnNorth();
        moving();
    }
}

void Shark::trai() {
    turnWest();
    moving();
    if (! onScreen()) {
        turnEast();
        moving();
    }
}

void Shark::phai() {
    turnEast();
    moving();
    if (! onScreen()) {
        turnWest();
        moving();
    }
}

