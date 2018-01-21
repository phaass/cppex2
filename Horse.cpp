//
// Created by phaass on 1/15/18.
//

#include "Horse.h"




int Horse::isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board)
{

    int yMove = new_y - y;
    int xMove = new_x - x;

    if ((xMove == 1 && yMove == 2) && !board.isOutOfBoard(new_x, new_y))
    {
        if ((board.getColorPlayer(new_x, new_y)) != currentPlayer)
        {
            return 0;
        }

    }
    return -1;
}

