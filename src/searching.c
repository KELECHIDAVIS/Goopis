#include "searching.h"

double alphaBeta(Board *board, int depth, double alpha, double beta) {
    if (depth == 0) 
        return evaluate(board); 

    // for all legal moves
    Move moves[MAX_MOVES];
    size_t numMoves = 0;
    //TODO: research move ordering to make this search more efficient
    getPseudoLegalMoves(board, moves, &numMoves);
    enumPiece currSide = board->whiteToMove ? nWhite : nBlack;

    for (size_t i = 0; i < numMoves; i++) {
        makeMove(board, moves[i]);
        if (!isSideInCheck(board, currSide)) { // legal move
            double score = -alphaBeta(board, depth - 1, -beta , -alpha);
            
            if(score>= beta)
                return beta; // opponent wouldn't allow move so return 
            if(score > alpha)
                alpha = score; 
        }
        unmakeMove(board, moves[i]);
    }
    return alpha; 
}