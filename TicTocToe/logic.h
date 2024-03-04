#ifndef _LOGIC__H
#define _logic__H

#define SIZE_X 30
#define SIZE_Y 15
#define EMPTY_CELL 2
#define O_CELL 0
#define X_CELL 1

int dx[4] = {1, 1, 0, -1};
int dy[4] = {0, 1, 1, 1};

struct Tictactoe
{
    int board[SIZE_Y][SIZE_X];
    int nextMove = O_CELL;
    int pt[SIZE_Y][SIZE_X][2][4];
    bool check = 0;

    void init()
    {
        for (int i = 0; i < SIZE_Y; i++)
            for (int j = 0; j < SIZE_X; j++) board[i][j] = EMPTY_CELL;
    }

    bool inside(int row, int col)
    {
        return row >= 0 && row < SIZE_Y && col >= 0 && col < SIZE_X;
    }

    void update(int row, int col, int nextMove, int i)
    {
        int rown = row + dy[i], coln = col + dx[i];

        while (inside(rown, coln) && board[rown][coln] == nextMove)
        {
            pt[rown][coln][nextMove][i] = pt[row][col][nextMove][i];
            rown += dy[i];
            coln += dx[i];
        }

        rown = row - dy[i], coln = col - dx[i];
        while (inside(rown, coln) && board[rown][coln] == nextMove)
        {
            pt[rown][coln][nextMove][i] = pt[row][col][nextMove][i];
            rown -= dy[i];
            coln -= dx[i];
        }
    }

    bool win()
    {
        if (check)
        {
            nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
            return true;
        }
        return false;
    }
    void move(int row, int col)
    {
        if (board[row][col] == EMPTY_CELL)
        {
            board[row][col] = nextMove;
            for (int i = 0; i < 4; i ++)
            {
                pt[row][col][nextMove][i] = 1;

                int rown = row + dy[i];
                int coln = col + dx[i];
                if (inside(rown, coln) && board[rown][coln] == nextMove)
                    pt[row][col][nextMove][i] += pt[rown][coln][nextMove][i];

                rown = row - dy[i];
                coln = col - dx[i];
                if (inside(rown, coln) && board[rown][coln] == nextMove)
                    pt[row][col][nextMove][i] += pt[rown][coln][nextMove][i];

                update(row, col, nextMove, i);
                if (pt[row][col][nextMove][i] == 5) check = 1;

            }
            nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
        }
    }

};

#endif // _LOGIC__H
