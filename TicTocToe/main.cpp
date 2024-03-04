#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true)
    {
        if ( SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
bool side(int x, int y)
{
    return (x - BOARD_X) % 30 != 0 && (y - BOARD_Y) % 30 != 0;
}
void processClick(int x, int y, Tictactoe& game)
{
    // chuyển tọa độ màn hình x, y thành tọa độ hàng cột của game
    int clickedCol = (x - BOARD_X) / CELL_SIZE;
    int clickedRow = (y - BOARD_Y) / CELL_SIZE;

    game.move(clickedRow, clickedCol);
}

int main(int argc, char* argv[])
{
    int x, y;
    char cell[2] = {'O', 'X'};
    bool quit;
    int stackn, maxn = SIZE_X * SIZE_Y;
    char key;

    do
    {
        Graphics graphics;
        graphics.init();

        SDL_Texture* background = graphics.loadTexture("img//bikiniBottom.jpg");
        graphics.prepareScene(background);
        graphics.presentScene();

        Tictactoe game;
        game.init();
        graphics.render(game);
        SDL_Event event;
        quit = false;
        stackn = 0;
        while (! quit && !game.win() && stackn < maxn)
        {
            SDL_PollEvent(&event);
            switch (event.type)
            {
                case SDL_QUIT:
                     quit = true;
                     break;
                case SDL_MOUSEBUTTONDOWN:
                     SDL_GetMouseState(&x, &y);
                     if (side(x, y)) processClick(x, y, game);
                     graphics.render(game);
                     stackn++;
                     break;
            }
        }
        cout << '\n';
        if (stackn < maxn) cout << cell[game.nextMove] << " win. \n";
        graphics.quit();
        cout << "Do you  want to play again? \n";
        cout << "Press y to continue, y to quit. \n";
        cout << "Enter your choise: ";
        cin >> key;
        cout << '\n';
    }
    while (key == 'y');
    cout << "You have quit game.";
    return 0;

}
