//
// Created by evyatar shalev on 07/01/2018.
//

#include <f2c.h>
#include "Pawn.h"







int Pawn::isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board)
{
    if (board.isOutOfBoard(new_x,new_y))
    {

        //print error
        return -1;
    }
    int yMove = abs(new_y - y);
    int xMove = abs(new_x - x);
    //to add:first move can be two steps.



    if ((xMove == 0 && yMove == 1) || (xMove == 0 && yMove == 2 ))
    {
        if ((board.isCellEmpty(new_x, new_y) == 0))
        {
            return 0;
        }
    }


    if (xMove == 1 && yMove == 1)
    {
        if ((board.getColorPlayer(new_x, new_y)) != currentPlayer)
        {
            return 0;
        }
    }


    return -1;


}

