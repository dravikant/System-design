#include "tictactoe.h"

int main(){

    TicTacToe tictactoe;
    tictactoe.initgame();
    cout<<"winner of the game is "<<tictactoe.startgame()<<endl;
    return 0;
}

// command to run

//g++ -I./include main.cpp src/player.cpp src/board.cpp src/TicTacToe.cpp -o tictactoe