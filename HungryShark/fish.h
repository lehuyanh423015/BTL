#ifndef FISH_H
#define FISH_H

class fish
{
public:
    int level;
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
    void speep_up()
    {
        speed = 4;
    }
    void speep_dn()
    {
        speed = 2;
    }
};

#endif // FISH_H
