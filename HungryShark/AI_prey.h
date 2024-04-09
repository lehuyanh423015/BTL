#ifndef AI_PREY_H
#define AI_PREY-H

#include <bits/stdc++.h>

#include "graphics.h"
#include "defs.h"
#include "shark.h"
using namespace std;

vector <Prey> fishs;
for (int i = 0; i < 10; i++)
    {
        int x = rand() % SCREEN_WIDTH;
        int y = rand() % SCREEN_HEIGHT;
        Prey prey(x, y);
        fishs.push_back(prey);
    }

#endif // AI_PREY_H
