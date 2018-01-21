cmake_minimum_required(VERSION 3.8)
project(cppex2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wextra -Wall -Wvla")


set(SOURCE_FILES chess.cpp Piece.cpp Piece.h Pawn.cpp Pawn.h King.cpp King.h Board.cpp Board.h Bishop.cpp Bishop.h
        Horse.cpp Horse.h Queen.cpp Queen.h Rook.cpp Rook.h)


add_executable(cppex2 ${SOURCE_FILES})