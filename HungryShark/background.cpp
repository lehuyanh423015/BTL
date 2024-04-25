#include "background.h"

void Screen::khoitao() {
    graphics.init();
    background = graphics.loadTexture(BACKGROUND_IMG);
}

void Screen::cbiManHinh() {
    graphics.prepareScene(background);
    SDL_RenderCopy(graphics.renderer, background, NULL, NULL);
}

void Screen::inManHinh() {
    graphics.presentScene();
}

void Screen::xoaManHinh(Shark& shark) {
    SDL_DestroyTexture(background);
    background = nullptr;

    SDL_DestroyTexture(shark.frightTexture);
    shark.frightTexture = nullptr;

    SDL_DestroyTexture(shark.fleftTexture);
    shark.fleftTexture = nullptr;

    SDL_DestroyTexture(shark.fupTexture);
    shark.fupTexture = nullptr;

    SDL_DestroyTexture(shark.fdownTexture);
    shark.fdownTexture = nullptr;

    graphics.quit();
}

void Screen::inShark(Shark& shark, int frame) {
    if (frame == 0) shark.sprite.tick();
    shark.render(graphics);
}

void Screen::inPrey(Prey& prey) {
    prey.render(graphics);
}
