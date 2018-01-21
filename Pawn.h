//
// Created by evyatar shalev on 07/01/2018.
//

#ifndef CPPEX2_PAWN_H
#define CPPEX2_PAWN_H

#include "Piece.h"
#include "Board.h"

class Pawn : public Piece{

public:




      static int isPossibleMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board);


};





#endif //CPPEX2_PAWN_H
