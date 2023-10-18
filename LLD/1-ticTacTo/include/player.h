#include "piece.h"
#include <iostream>
#include <string>
#pragma once
using namespace std;

class Player{

    private:
        string name;
        PlayingPiece playingpiece;
    public:
        Player(string name,PlayingPiece piece);
        string getName();
        void setName(string name);
        PlayingPiece getplayingpiece();
        void setplayingpiece(PlayingPiece piece);
};