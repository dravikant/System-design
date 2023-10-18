#include "board.h"
#include<vector>
#include<iostream>
using namespace std;


Board::Board(int size): size(size){
    board.resize(size,vector<PlayingPiece>(size,PlayingPiece(PieceType::None)));
}

bool Board::addPiece(int row, int column, PlayingPiece piece){
    if(board[row][column].getPieceType() != PieceType::None){
        return false;
    }
    board[row][column] = piece;
    return true;
}

void Board::printBoard(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(board[i][j].getPieceType() == PieceType::None){
                cout<<" ";
            }
            else{
                cout<<board[i][j].getPieceType();
            }
            cout<<" | ";
        }
        cout<<endl;
    }
}

vector<pair<int,int> > Board::getFreeCells(){
    vector<pair<int,int> > freecells;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(board[i][j].getPieceType() == PieceType::None){
                freecells.push_back(make_pair(i,j));
            }
        }
        
    }

    return freecells;
}

int Board::getsize(){
    return size;
}