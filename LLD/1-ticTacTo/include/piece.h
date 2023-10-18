#pragma once

enum PieceType{
    X,
    O,
    None
};


class PlayingPiece{
    private:
        PieceType piecetype;
    public:
        PlayingPiece(PieceType piecetype) : piecetype(piecetype){};
        PieceType getPieceType(){
            return piecetype;
        }
};

class PieceX : public PlayingPiece{
    public:
        PieceX():PlayingPiece(PieceType::X){};
};

class PieceO : public PlayingPiece{
    public:
        PieceO():PlayingPiece(PieceType::O){};
};