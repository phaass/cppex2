//
// Created by phaass on 1/15/18.
//

#include <f2c.h>
#include "Queen.h"



  int Queen::isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board){

    const int yMove = new_y - y;
    const int xMove = new_x - x;

    if ((xMove == 0 || yMove == 0 || xMove == yMove) && !board.isOutOfBoard(new_x, new_y))
    {
        if ((board.getColorPlayer(new_x, new_y)) != currentPlayer)
        {

            for (int i = min(x, new_x) , j = min(y, new_y); i < max(x, new_x), j < max(y, new_y) ; i++, j++)
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
        else{
            return -1;
        }
    }
    return -1;
};


