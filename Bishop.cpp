//
// Created by phaass on 1/15/18.
//

#include <f2c.h>
#include "Bishop.h"



int Bishop::isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board)
{


    int yMove = abs(new_y - y);
    int xMove = abs(new_x - x);

    if ((xMove == yMove) && !board.isOutOfBoard(new_x, new_y))
    {
        if ((board.getColorPlayer(new_x, new_y)) != currentPlayer)
        {

            for (int i = min(x, new_x)+1 , j = min(y, new_y)+1; i < max(x, new_x), j < max(y, new_y) ; i++, j++)
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