#ifndef SHARK_H
#define SHARK_H

#define INITIAL_SPEED 3
#define PREY_SIZE 10
#define SHARK_SIZE 30

bool inside(int x, int y, SDL_Rect r) {
    return x > r.x && x < r.x+r.w && y > r.y && y < r.y+r.h;
}

bool overlap(const SDL_Rect& r1, const SDL_Rect& r2) {
    return inside(r1.x, r1.y, r2) || inside(r1.x + r1.w, r1.y, r2) ||
            inside(r1.x, r1.y+r1.h, r2) || inside(r1.x+r1.w, r1.y+r1.h, r2);
}

class fish
{
public:
    int dx, dy;
    int speed;
    SDL_Rect rect;

    void turnNorth() {
        dy = -speed;
        dx = 0;
    }
    void turnSouth() {
        dy = speed;
        dx = 0;
    }
    void turnWest() {
        dy = 0;
        dx = -speed;
    }
    void turnEast() {
        dy = 0;
        dx = speed;
    }
    void moving() {
        rect.x += dx;
        rect.y += dy;
    }
};

class Prey : public fish{
public:
    Prey(int x, int y) {
        dx = 0;
        dy = 0;
        speed = 1;
        rect.x = x;
        rect.y = y;
        rect.h = PREY_SIZE;
        rect.w = PREY_SIZE;
    }
};

class Shark : public fish{
public:
    Shark(int x, int y) : fish() {
        dx = 0;
        dy = 0;
        speed = INITIAL_SPEED;
        rect.x = x;
        rect.y = y;
        rect.h = SHARK_SIZE;
        rect.w = SHARK_SIZE;
    }

    bool canEat(const Prey& prey) {
        return overlap(rect, prey.rect);
    }

    void grow() {
        rect.h += 1;
        rect.w += 1;
    }
};

void render(const Prey& prey, const Graphics& graphics) {
    SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 0, 255); // green
    SDL_RenderFillRect(graphics.renderer, &prey.rect);
}

void render(const Shark& shark, const Graphics& graphics) {
    SDL_SetRenderDrawColor(graphics.renderer, 0, 255, 200, 255); // green
    SDL_RenderFillRect(graphics.renderer, &shark.rect);
}

bool gameOver(const Shark& shark) {
    return shark.rect.x < 0 || shark.rect.x + shark.rect.w >= SCREEN_WIDTH ||
           shark.rect.y < 0 || shark.rect.y + shark.rect.h >= SCREEN_HEIGHT;
}

#endif // SHARK_H
