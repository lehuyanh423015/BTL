#include "shark.h"

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

void Shark::khoitao(Graphics& graphics) {
    frightTexture = graphics.loadTexture(FISH_RIGHT);
    fright.init(frightTexture, FRAMES, RIGHT_CLIPS);

    fleftTexture = graphics.loadTexture(FISH_LEFT);
    fleft.init(fleftTexture, FRAMES, LEFT_CLIPS);

    fupTexture = graphics.loadTexture(FISH_UP);
    fup.init(fupTexture, FRAMES, UP_CLIPS);

    fdownTexture = graphics.loadTexture(FISH_DOWN);
    fdown.init(fdownTexture, FRAMES, DOWN_CLIPS);

    sprite = fright;
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
    if (level > 8) level = 8;
    rect.h = 36 + (level - 2) * 6;
    rect.w = 36 + (level - 2) * 6;
}

void Shark::render(const Graphics& graphics) {
    const SDL_Rect* clip = sprite.getCurrentClip();
    SDL_Rect renderQuad = {rect.x, rect.y, rect.w, rect.h};
    SDL_RenderCopy(graphics.renderer, sprite.texture, clip, &renderQuad);
}

void Shark::len() {
    turnNorth();
    sprite = fup;
    moving();
    if (! onScreen()) {
        turnSouth();
        moving();
    }
}

void Shark::xuong() {
    turnSouth();
    sprite = fdown;
    moving();
    if (! onScreen()) {
        turnNorth();
        moving();
    }
}

void Shark::trai() {
    turnWest();
    sprite = fleft;
    moving();
    if (! onScreen()) {
        turnEast();
        moving();
    }
}

void Shark::phai() {
    turnEast();
    sprite = fright;
    moving();
    if (! onScreen()) {
        turnWest();
        moving();
    }
}

