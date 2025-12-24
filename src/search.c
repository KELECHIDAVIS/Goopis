#include "search.h"

double negamax(Board *board, int depth) {
    if (depth == 0)
        return evaluate(board);

    double max = DBL_MIN;

    // for all legal moves
    Move moves[MAX_MOVES];
    size_t numMoves = 0;
    getPseudoLegalMoves(board, moves, &numMoves);
    enumPiece currSide = board->whiteToMove ? nWhite : nBlack;

    for (size_t i = 0; i < numMoves; i++) {
        makeMove(board, moves[i]);
        if (!isSideInCheck(board, currSide)) { // legal move
            double score = -negamax(board, depth - 1);
            
            if (score> max ) 
                max = score ; 
        }
        unmakeMove(board, moves[i]);
    }
    return max;
}