//
// Created by phaass on 1/15/18.
//

#ifndef CPPEX2_BISHOP_H
#define CPPEX2_BISHOP_H


#include "Piece.h"

class Bishop: public Piece
{

public:

     static int isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board);
};


#endif //CPPEX2_BISHOP_H
