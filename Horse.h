//
// Created by phaass on 1/15/18.
//

#ifndef CPPEX2_HORSE_H
#define CPPEX2_HORSE_H


#include "Board.h"
#include "Piece.h"

class Horse: public Piece
{
public:


     static int isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board);
};


#endif //CPPEX2_HORSE_H
