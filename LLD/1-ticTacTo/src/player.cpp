#include "piece.h"
#include "player.h"
#include <string>




Player::Player(string name,PlayingPiece piece): name(name),playingpiece(piece){};
string Player::getName(){
    return name;
}
void Player::setName(string name){
    this->name = name;
}    
PlayingPiece Player::getplayingpiece(){
    return playingpiece;
}
void Player::setplayingpiece(PlayingPiece piece){
    playingpiece = piece;
}
