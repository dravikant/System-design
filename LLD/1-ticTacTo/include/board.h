#pragma once
#include "piece.h"
#include <vector>

class Board {
private:
    int size;
    

public:
    std::vector<std::vector<PlayingPiece> > board;
    Board(int size);
    bool addPiece(int row, int column, PlayingPiece piece);
    void printBoard();
    std::vector<std::pair<int, int> > getFreeCells();
    int getsize();
};