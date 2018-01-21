//
// Created by phaass on 1/15/18.
//

#include <algorithm>
#include "Rook.h"




int Rook::isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board)
{
    const int yMove = new_y - y;
    const int xMove = new_x - x;

    if ((xMove == 0 || yMove == 0) && !board.isOutOfBoard(new_x, new_y))
    {
        if ((board.getColorPlayer(new_x, new_y)) != currentPlayer)
        {

            for (int i = x+1, j = y+1; i < new_x, j < new_y; i++, j++)
            {
                if ((board.isCellEmpty(i, j) == 0))
                {
                    continue;
                }
                else
                {
                    return -1;
                }

            }
            return 0;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}