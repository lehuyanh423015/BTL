#include "background.h"

void Screen::khoitao() {
    graphics.init();
    background = graphics.loadTexture(BACKGROUND_IMG);
    pause = graphics.loadTexture(PAUSE);
    menu = graphics.loadTexture(MENU);

}

void Screen::menugame() {
    graphics.prepareScene(menu);
    SDL_RenderCopy(graphics.renderer, menu, NULL, NULL);
}

void Screen::cbiManHinh() {
    graphics.prepareScene(background);
    SDL_RenderCopy(graphics.renderer, background, NULL, NULL);
    graphics.renderPicture(pause, 10, 10, 40, 40);
}

void Screen::inManHinh() {
    graphics.presentScene();
}

void Screen::xoaManHinh(Shark& shark) {
    SDL_DestroyTexture(background);
    background = nullptr;

    SDL_DestroyTexture(pause);
    pause = nullptr;


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
    string lv = "Level: " + to_string(shark.level);
    Font level(lv.c_str(), 24);
    string ex = "Exp: " + to_string(shark.exp)
            + "/" + to_string(shark.level * 50);
    if (shark.level == 8) ex = "Exp: " + to_string(shark.exp)
            + "/ oo";
    Font exp(ex.c_str(), 24);
    level.renderText(820, 10, graphics);
    exp.renderText(820, 40, graphics);

    SDL_DestroyTexture(level.Text);
    TTF_CloseFont(level.font);

    SDL_DestroyTexture(exp.Text);
    TTF_CloseFont(exp.font);
}

void Screen::inPrey(Prey& prey) {
    prey.render(graphics);
    string lv = "Lv: " + to_string(prey.level);
    Font level(lv.c_str(), 20);
    level.renderText(prey.rect.x + 2,
                     prey.rect.y + prey.rect.h + 2, graphics);

    SDL_DestroyTexture(level.Text);
    TTF_CloseFont(level.font);
}
