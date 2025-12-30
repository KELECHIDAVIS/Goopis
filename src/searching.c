#include "searching.h"

//searches and sets board's best move for that position 
double alphaBeta(Board *board, int depth, double alpha, double beta) {
    if (board->historyPly >= MAX_SEARCH_DEPTH - 10) { // Leave some margin
        return evaluate(board);                       // Emergency exit
    }
    
    if (depth <= 0) 
        return evaluate(board);

    // Check for draw by fifty-move rule
    if (board->halfmoveClock >= 100) {
        return DRAW_SCORE;
    }
    // for all legal moves
    Move move_list[MAX_MOVES];
    size_t numMoves = 0;

    // get psuedo legal moves and sort them
    getPseudoLegalMoves(board, move_list, &numMoves);
    sortMoveList(board, move_list, numMoves);

    enumPiece currSide = board->whiteToMove ? nWhite : nBlack;
    size_t legalMoveCount = 0;

    for (size_t i = 0; i < numMoves; i++) {
       
        makeMove(board, move_list[i]);

        if (!isSideInCheck(board, currSide)) { // legal move
            legalMoveCount++;
            double score = -alphaBeta(board, depth - 1, -beta , -alpha);
            
            unmakeMove(board, move_list[i]); // unmake move before returning 
            
            if(score>= beta)
                return beta; // opponent wouldn't allow move so return 

            if(score > alpha)
                alpha = score;

        }else{ // unmake illegal move 
            unmakeMove(board, move_list[i]);
        }
        
    }

    // No legal moves found - check for checkmate or stalemate
    if (legalMoveCount == 0) {
        if (isSideInCheck(board, currSide)) {
            // Checkmate: return a mate score adjusted by depth
            // This makes the engine prefer shorter mates
            return -MATE_SCORE + board->historyPly;
        } else {
            // Stalemate: it's a draw
            return DRAW_SCORE;
        }
    }

    return alpha; // alpha being returned is probably neg inifinity 
}

Move getBestMove(Board *board, int depth) {
    Move move_list[MAX_MOVES];
    size_t numMoves = 0;

    getPseudoLegalMoves(board, move_list, &numMoves);
    sortMoveList(board, move_list, numMoves);

    enumPiece currSide = board->whiteToMove ? nWhite : nBlack;

    Move bestMove = 0;
    double bestScore = -INFINITY;

    for (size_t i = 0; i < numMoves; i++) {
        makeMove(board, move_list[i]);

        if (!isSideInCheck(board, currSide)) {
            double score = -alphaBeta(board, depth - 1, -INFINITY, INFINITY);
            unmakeMove(board, move_list[i]);

            if (score > bestScore) {
                bestScore = score;
                bestMove = move_list[i];
            }
        } else {
            unmakeMove(board, move_list[i]);
        }
    }

    // If no legal move was found, we're in checkmate or stalemate
    // Return 0 (invalid move) - caller should check for game over
    return bestMove;
}