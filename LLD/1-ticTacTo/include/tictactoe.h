#include "player.h"
#include "board.h"
#include<queue>
#include<string>
#pragma once

class TicTacToe{
    private:
        queue<Player*> players;
        Board* gameboard;
    public:
        void initgame();
        string startgame();
        bool isthereaWinner(int row, int column, PieceType);
};