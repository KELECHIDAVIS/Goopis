#include "searching.h"

SearchInfo searchInfo;

void initSearch(int timeMs) {
    searchInfo.startTime = clock();
    searchInfo.allocatedTime = timeMs;
    searchInfo.timeUp = false;
}

int getElapsedTime() {
    clock_t current = clock();
    return (int)(((double)(current - searchInfo.startTime) / CLOCKS_PER_SEC) * 1000);
}

bool shouldStop() {
    if (getElapsedTime() >= searchInfo.allocatedTime) {
        searchInfo.timeUp = true;
        return true;
    }
    return false;
}

static uint64_t nodeCount = 0;

//searches and sets board's best move for that position 
double alphaBeta(Board *board, int depth, double alpha, double beta) {

    nodeCount++;

    // Check time:
    // 1. At higher depths (cheap since few nodes)
    // 2. Every 2048 nodes at lower depths (where most time is spent)
    if (depth >= 4 || (nodeCount & 2047) == 0) {
        if (shouldStop()) {
            return evaluate(board);
        }
    }

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

Move getBestMove(Board *board, int maxTimeMs) {
    Move bestMove = 0;
    double bestScore = -INFINITY;

    // Initialize search with allocated time
    initSearch(maxTimeMs);

    // Iterative deepening: search depth 1, 2, 3, ... until time runs out
    for (int depth = 1; depth < MAX_SEARCH_DEPTH; depth++) {
        Move move_list[MAX_MOVES];
        size_t numMoves = 0;

        getPseudoLegalMoves(board, move_list, &numMoves);
        sortMoveList(board, move_list, numMoves);

        enumPiece currSide = board->whiteToMove ? nWhite : nBlack;

        Move iterationBestMove = 0;
        double iterationBestScore = -INFINITY;
        bool completedDepth = true;

        for (size_t i = 0; i < numMoves; i++) {
            makeMove(board, move_list[i]);

            if (!isSideInCheck(board, currSide)) {
                double score = -alphaBeta(board, depth - 1, -INFINITY, INFINITY);
                unmakeMove(board, move_list[i]);

                // If we ran out of time during this depth, don't trust the results
                if (searchInfo.timeUp) {
                    completedDepth = false;
                    break;
                }

                if (score > iterationBestScore) {
                    iterationBestScore = score;
                    iterationBestMove = move_list[i];
                }
            } else {
                unmakeMove(board, move_list[i]); // unmake illegal move 
            }
        }

        // Only update best move if we completed this depth
        if (completedDepth && iterationBestMove) {
            bestMove = iterationBestMove;
            bestScore = iterationBestScore;

            // Optional: Print info for debugging (UCI "info" command)
            printf("info depth %d score cp %d time %d\n",
                   depth, (int)bestScore, getElapsedTime());
        }

        // Stop if time is up or we found a mate
        if (searchInfo.timeUp || bestScore > MATE_SCORE - 100) {
            break;
        }
    }

    return bestMove;
}