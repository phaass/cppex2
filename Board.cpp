//
// Created by phaass on 1/14/18.
//

#include <iostream>
#include "Board.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "Horse.h"
#include "King.h"

int check, kingWhiteX, kingBlackX, kingWhiteY, kingBlackY;
int infoTools[8][8][3] = {none};


Board::Board()
{
    kingWhiteX = 3;
    kingWhiteY = 0;
    kingBlackX = 3;
    kingBlackY = 7;
}

/**
 * Initializing a game board by filling in the "infoTools" table
 */
void Board::initialization()
{
//  Fills information about the color of the board
// (green or blue) and the color of the player in
//  each slot (white or black)
    int k = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (k % 2 == 0)
            {
                infoTools[i][j][2] = greenColor;
                infoTools[i][j][0] = none;
            }
            else
            {
                infoTools[i][j][2] = blueColor;
                infoTools[i][j][0] = none;
            }
            k++;
        }
        k++;
    }

    infoTools[0][0][0] = rook;
    infoTools[0][1][0] = horse;
    infoTools[0][2][0] = bishop;
    infoTools[0][3][0] = king;
    infoTools[0][4][0] = queen;
    infoTools[0][5][0] = bishop;
    infoTools[0][6][0] = horse;
    infoTools[0][7][0] = rook;


    infoTools[1][0][0] = pawn;
    infoTools[1][1][0] = pawn;
    infoTools[1][2][0] = pawn;
    infoTools[1][3][0] = pawn;
    infoTools[1][4][0] = pawn;
    infoTools[1][5][0] = pawn;
    infoTools[1][6][0] = pawn;
    infoTools[1][7][0] = pawn;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            infoTools[j][i][1] = whiteTool;
        }
    }


    infoTools[7][0][0] = rook;
    infoTools[7][1][0] = horse;
    infoTools[7][2][0] = bishop;
    infoTools[7][3][0] = king;
    infoTools[7][4][0] = queen;
    infoTools[7][5][0] = bishop;
    infoTools[7][6][0] = horse;
    infoTools[7][7][0] = rook;


    infoTools[6][0][0] = pawn;
    infoTools[6][1][0] = pawn;
    infoTools[6][2][0] = pawn;
    infoTools[6][3][0] = pawn;
    infoTools[6][4][0] = pawn;
    infoTools[6][5][0] = pawn;
    infoTools[6][6][0] = pawn;
    infoTools[6][7][0] = pawn;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 6; j < 8; j++)
        {
            infoTools[j][i][1] = blackTool;
        }
    }
}

const int Board::isCellEmpty(int x, int y) const
{
    return infoTools[y][x][0] == none ? 0 : 1;
}

const int Board::getToolPlayer(int x, int y) const
{

    return infoTools[y][x][0];
}

const int Board::getColorPlayer(int x, int y) const
{
    return infoTools[y][x][1];

}

void Board::movePiece(int x, int y, int new_x, int new_y)
{
    int toolType = infoTools[y][x][0];
    int toolColor = infoTools[y][x][1];
    infoTools[y][x][0] = none;
    infoTools[y][x][1] = none;
    infoTools[new_y][new_x][0] = toolType;
    infoTools[new_y][new_x][1] = toolColor;
}

const int Board::isOutOfBoard(int x, int y) const
{
    if (x > 8 | y > 8)
    {
        return 1;
    }
    return 0;
}



std::string intToStr(int index)
{
    switch (index)
    {

        case 0:
            return "\u265F";
        case 1:
            return "\u265C";
        case 2:
            return "\u265E";
        case 3:
            return "\u265D";
        case 4:
            return "\u265A";
        case 5:
            return "\u265B";
        case 6:
            return " ";  // -----------------------------

        default:
            return " ";
    }
}

int Board::printBoard()
{
    std::cout << "  "; // ---------------------------
    std::cout << "ABCDEFGH\n\n";
    std::string temp;
    for (int i = 0; i < 8; i++)
    {

        std::cout << 8 - i << " ";
        for (int j = 0; j < 8; j++)
        {
            temp = "\33[";
            temp += std::to_string(infoTools[7 - i][j][2]);
            temp += ";";
            temp += std::to_string(infoTools[7 - i][j][1]);
            temp += "m";
            temp += intToStr(infoTools[7 - i][j][0]);
            temp += "\33[0m";

            std::cout << temp;

        }
        std::cout << " " << 8 - i << "\n";
//        std::cout << "\n";
    }

    std::cout << "\n  ABCDEFGH\n"; // ---------------------------
//    std::cout << "\nABCDEFGH";

    return 0;
}

int Board::makeMove(int x, int y, int new_x, int new_y, int currentPlayer, Board board)
{
    int kingX, kingY;
    if (currentPlayer == whiteTool)
    {
        kingX = kingWhiteX;
        kingY = kingWhiteY;

    }
    else
    {
        kingX = kingBlackX;
        kingY = kingBlackY;
    }


    if ((getColorPlayer(x, y) == currentPlayer) && (isCellEmpty(x, y) != 0))
    {
        switch (getToolPlayer(x, y))
        {
            case pawn:
                if (Pawn::isPossibleMove(x, y, new_x, new_y, currentPlayer, board) == 0)
                {
                    if (King::isCheck(kingX, kingY, currentPlayer, board) != 0)
                    {
                        board.movePiece(x,y,new_x,new_y);
                        return 0;
                    }
                }
                break;
            case bishop:
                if (Bishop::isPossibleMove(x, y, new_x, new_y, currentPlayer, board) == 0)
                {
                    if (King::isCheck(kingX, kingY, currentPlayer, board) != 0)
                    {
                        board.movePiece(x,y,new_x,new_y);
                        return 0;
                    }
                }
                break;
            case rook:
                if (Rook::isPossibleMove(x, y, new_x, new_y, currentPlayer, board) == 0)
                {
                    if (King::isCheck(kingX, kingY, currentPlayer, board) != 0)
                    {
                        board.movePiece(x,y,new_x,new_y);
                        return 0;
                    }
                }
                break;
            case queen:
                if (Queen::isPossibleMove(x, y, new_x, new_y, currentPlayer, board) == 0)
                {
                    if (King::isCheck(kingX, kingY, currentPlayer, board) != 0)
                    {
                        board.movePiece(x,y,new_x,new_y);
                        return 0;
                    }
                }
                break;

            case horse:
                if (Horse::isPossibleMove(x, y, new_x, new_y, currentPlayer, board) == 0)
                {
                    if (King::isCheck(kingX, kingY, currentPlayer, board) != 0)
                    {
                        board.movePiece(x,y,new_x,new_y);
                        return 0;
                    }
                }
                break;

            case king:
                if (King::isPossibleMove(x, y, new_x, new_y, currentPlayer, board) == 0)
                {
                    if (King::isCheck(kingX, kingY, currentPlayer, board) != 0)
                    {
                        board.movePiece(x,y,new_x,new_y);
                        board.changeKingPosition(new_x, new_y, currentPlayer);
                        return 0;
                    }
                }
                break;

            default:
                return -1;
        }
    }
    return -1;
}


int Board::changeKingPosition(int new_x, int new_y, int currentPlayer)
{
    if (currentPlayer == whiteMove)
    {
        kingWhiteX = new_x;
        kingWhiteY = new_y;

    }
    else
    {
        kingBlackX = new_x;
        kingBlackY = new_y;
    }

    return 0;
}

int Board::isCheckMate(int currentPlayer, Board board)
{
    int kingX, kingY;
    if (currentPlayer == whiteTool)
    {
        kingX = kingWhiteX;
        kingY = kingWhiteY;

    }
    else
    {
        kingX = kingBlackX;
        kingY = kingBlackY;
    }
    return (King::isCheck(kingX, kingY, currentPlayer, board) && King::isCheck(kingX + 1, kingY, currentPlayer, board)
            && King::isCheck(kingX - 1, kingY, currentPlayer, board) &&
            King::isCheck(kingX, kingY + 1, currentPlayer, board) &&
            King::isCheck(kingX, kingY - 1, currentPlayer, board) &&
            King::isCheck(kingX + 1, kingY + 1, currentPlayer, board) &&
            King::isCheck(kingX - 1, kingY - 1, currentPlayer, board)) ? 1 : 0;
}