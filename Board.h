//
// Created by phaass on 1/14/18.
//

#ifndef CPPEX2_BOARD_H
#define CPPEX2_BOARD_H
#define greenColor  42
#define blueColor   46
#define whiteTool   37
#define blackTool   30


#define pawn 0
#define rook 1
#define horse 2
#define bishop 3
#define king 4
#define queen 5
#define none 6

#define whiteMove 0

class Board {
public:


    explicit Board();

    const int isCellEmpty(int x, int y) const;

    void initialization();

    const int getToolPlayer(int x, int y) const;

    void movePiece(int x, int y, int new_x, int new_y);

    const int isOutOfBoard(int x, int y) const;

    const int getColorPlayer(int x, int y) const;

    void CheckOn();

    int printBoard();

    int makeMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board);

    int changeKingPosition(int new_x, int new_y, int currentPlayer);

    int isCheckMate(int currentPlayer, Board board);
};


#endif //CPPEX2_BOARD_H
