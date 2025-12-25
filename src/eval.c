#include "eval.h"

// TODO: check if game is over in current position and return a certain value for that 
//TODO: make this quiesience and more complex than this simplified version 

// returns how good position is for current side to move 
double evaluate(const Board *board) {
    
    int whoToMove = board->whiteToMove ? 1 : -1 ; 
    double score = 0; 
    int pieceWeights[] ={1,3,3,5,9,200}; //p,n,b,r,q,k
    for (enumPiece piece = nPawn; piece <=nKing; piece++){
        int pieceIndx=piece-2; // nPawn = 2
        int materialWeight = pieceWeights[pieceIndx]; 
        int numWhitePieces= __builtin_popcountll(getSpecificColorPieces(board, nWhite,piece)); 
        int numBlackPieces= __builtin_popcountll(getSpecificColorPieces(board, nBlack,piece)); 

        score+= materialWeight * (numWhitePieces-numBlackPieces) * whoToMove;  
    }
    
    return score; 
}