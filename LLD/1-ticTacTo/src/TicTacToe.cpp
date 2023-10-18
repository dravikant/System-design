#include<iostream>
#include<queue>
#include "player.h"
#include "board.h"
#include "tictactoe.h"
using namespace std;


void TicTacToe::initgame(){
    
    Player* player1 = new Player("Raj",PieceX());
    Player* player2 = new Player("Shubh",PieceO());

    players.push(player1);
    players.push(player2);

    gameboard = new Board(3); 
}

string TicTacToe::startgame(){

    bool nowinner = true;

    while(nowinner){

        //take first player from queue for turn and push it back to end

        Player* playerturn = players.front();
        

        gameboard->printBoard();

        vector<pair<int,int> > freecells = gameboard->getFreeCells();
        if(freecells.size()==0){
            nowinner = false;
            continue;
        }

        //read user input
        cout<<" player "<<playerturn->getName()<<" Enter row and column "<<endl;
        int row,column;
        cin>>row;
        cin>>column;

        //place the piece
        bool sucessplacement = gameboard->addPiece(row,column,playerturn->getplayingpiece());
        if(!sucessplacement){
            cout<<"Incorrect position Try again"<<endl;
            continue;
        }

        players.pop();
        players.push(playerturn);
        bool winner = isthereaWinner( row,  column, playerturn->getplayingpiece().getPieceType());
        if(winner){
            return playerturn->getName();
            
        }

    }

    return "tie";

}

bool TicTacToe::isthereaWinner(int row,int column,PieceType piecetype){
    bool rowmatch = true;
    bool columnmatch =true;
    bool diagonalmatch =true;
    bool antidiagonalmatch =true;

    for(int i=0;i<gameboard->getsize();i++){
        if(gameboard->board[row][i].getPieceType() != piecetype){
            rowmatch=false;
        }
    }

    for(int i=0;i<gameboard->getsize();i++){
        if(gameboard->board[i][column].getPieceType() != piecetype){
            columnmatch=false;
        }
    }   

    for(int i=0,j=0;i<gameboard->getsize();i++,j++){
        if(gameboard->board[i][j].getPieceType() != piecetype){
            diagonalmatch=false;
        }
    }  

    for(int i=0,j=gameboard->getsize()-1;i<gameboard->getsize();i++,j--){
        if(gameboard->board[i][j].getPieceType() != piecetype){
            antidiagonalmatch=false;
        }
    }  

    return rowmatch || columnmatch ||diagonalmatch || antidiagonalmatch;
}