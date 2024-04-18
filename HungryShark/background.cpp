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

void Screen::xoaManHinh() {
    SDL_DestroyTexture(background);
    graphics.quit();
}

void Screen::inShark(Shark& shark) {
    shark.render(graphics);
}

void Screen::inPrey(Prey& prey) {
    prey.render(graphics);
}
