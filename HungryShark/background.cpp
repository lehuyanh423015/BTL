#include "background.h"

void Screen::init_grap_music() {
    graphics.init();
    sound.nhacNen();
}

void Screen::init_menu() {
    menu = graphics.loadTexture(MENU);
}
void Screen::render_menu() {

    graphics.prepareScene(menu);
    SDL_RenderCopy(graphics.renderer, menu, NULL, NULL);
    graphics.presentScene();
}

void Screen::xoa_menu() {
    SDL_DestroyTexture(menu);
    menu = nullptr;
}

void Screen::init_gameplay() {
    background = graphics.loadTexture(BACKGROUND);
    pause = graphics.loadTexture(PAUSE);
}

void Screen::render_gameplay() {
    graphics.prepareScene(background);
    SDL_RenderCopy(graphics.renderer, background, NULL, NULL);
    graphics.renderPicture(pause, 10, 10, 40, 40);
}

void Screen::xoa_gamePlay() {
    SDL_DestroyTexture(background);
    background = nullptr;

    SDL_DestroyTexture(pause);
    pause = nullptr;
}

void Screen::init_pause() {
    gPause = graphics.loadTexture(G_PAUSE);
}

void Screen::render_pause() {
    graphics.renderPicture(gPause, 250, 150, 460, 260);
}

void Screen::xoa_pause() {
    SDL_DestroyTexture(gPause);
    gPause = nullptr;
}

void Screen::init_died() {
    died = graphics.loadTexture(DIED);
}

void Screen::render_died() {
    graphics.renderPicture(died, 120, 80, 720, 405);
}

void Screen::xoa_died() {
    SDL_DestroyTexture(died);
    died = nullptr;
}

void Screen::render_shark(Shark& shark, int frame) {
    if (frame == 0) shark.sprite.tick();
    shark.render_shark(graphics);
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

void Screen::render_prey(Prey& prey) {
    prey.render(graphics);
    string lv = "Lv: " + to_string(prey.level);
    Font level(lv.c_str(), 20);
    level.renderText(prey.rect.x + 2,
                     prey.rect.y + prey.rect.h + 2, graphics);

    SDL_DestroyTexture(level.Text);
    TTF_CloseFont(level.font);
}
