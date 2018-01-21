//
// Created by evyatar shalev on 07/01/2018.
//

#ifndef CPPEX2_PIECE_GAME_H
#define CPPEX2_PIECE_GAME_H

#include "Board.h"

#define whiteMove 0
#define blackMove 1

#define pawn 0
#define rook 1
#define horse 2
#define bishop 3
#define king 4
#define queen 5
#define none 6


class Piece
{

protected:


    //    all pure virtual:
    static int move(int x, int y, int new_x, int new_y, int currentPlayer, Board board);

    static int isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board);

};


#endif //CPPEX2_PIECE_GAME_H