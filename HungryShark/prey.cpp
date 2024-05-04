#include "prey.h"

bool Prey::onScreen() {
    return rect.x <= SCREEN_WIDTH
        && rect.y <= SCREEN_HEIGHT
        && rect.x + rect.w >= 0
        && rect.y + rect.h >= 0;
}

void Prey::render(const Graphics& graphics) {
    SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 0, 255); // green
    SDL_RenderFillRect(graphics.renderer, &rect);
}
