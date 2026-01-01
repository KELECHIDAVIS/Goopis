#include "searching.h"

// --- Configuration ---
// 64MB is safe for Heroku's 512MB limit
#define TT_SIZE_MB 64
#define MATE_BOUND (MATE_SCORE - MAX_SEARCH_DEPTH)

SearchInfo searchInfo;
TTEntry *transTable = NULL;
size_t ttEntryCount = 0;

// --- Helper: Normalize Mate Scores ---
// Converts "Mate at absolute ply X" to "Mate in N moves (infinite reference)"
static int scoreToTT(int score, int ply) {
    if (score > MATE_BOUND)
        return score + ply;
    if (score < -MATE_BOUND)
        return score - ply;
    return score;
}

// Converts "Mate in N moves" back to "Mate at absolute ply X" for the current search
static int scoreFromTT(int score, int ply) {
    if (score > MATE_BOUND)
        return score - ply;
    if (score < -MATE_BOUND)
        return score + ply;
    return score;
}

// --- Memory Management ---
void initTransTable(void) {
    if (transTable != NULL)
        free(transTable);

    // Calculate entries based on MB size
    ttEntryCount = (TT_SIZE_MB * 1024 * 1024) / sizeof(TTEntry);

    // Use calloc to zero the memory (prevents garbage bugs)
    transTable = (TTEntry *)calloc(ttEntryCount, sizeof(TTEntry));

    if (transTable == NULL) {
        fprintf(stderr, "CRITICAL: Failed to allocate Transposition Table!\n");
        exit(1);
    }

    fprintf(stderr, "TT Initialized: %d MB (%zu entries)\n", TT_SIZE_MB, ttEntryCount);
}

void clearTransTable(void) {
    if (transTable != NULL) {
        memset(transTable, 0, ttEntryCount * sizeof(TTEntry));
    }
}

void freeTransTable(void) {
    if (transTable != NULL) {
        free(transTable);
        transTable = NULL;
    }
}

// --- TT Access ---
bool probeTransTable(Board *board, int depth, int alpha, int beta,
                     int *score, Move *bestMove) {
    if (transTable == NULL)
        return false;

    size_t index = board->zobristKey % ttEntryCount;
    TTEntry *entry = &transTable[index];

    // Check for hash collision
    if (entry->zobristKey != board->zobristKey) {
        return false;
    }

    // Always provide the best move for move ordering!
    if (bestMove != NULL) {
        *bestMove = entry->bestMove;
    }

    // We can only cut off if the stored depth is >= current required depth
    if (entry->depth < depth) {
        return false;
    }

    // Convert stored score to be relative to current ply
    int ttScore = scoreFromTT(entry->eval, board->historyPly);

    switch (entry->type) {
    case TT_EXACT:
        *score = ttScore;
        return true;
    case TT_BETA:
        if (ttScore >= beta) {
            *score = beta;
            return true;
        }
        break;
    case TT_ALPHA:
        if (ttScore <= alpha) {
            *score = alpha;
            return true;
        }
        break;
    }

    return false;
}

void storeTransTable(Board *board, int depth, int score,
                     TTType type, Move bestMove) {
    if (transTable == NULL)
        return;

    size_t index = board->zobristKey % ttEntryCount;
    TTEntry *entry = &transTable[index];

    // Depth-Preferred Replacement Strategy
    if (entry->zobristKey == 0 ||
        entry->zobristKey == board->zobristKey ||
        depth >= entry->depth) {

        entry->zobristKey = board->zobristKey;
        // Normalize score before storing
        entry->eval = scoreToTT(score, board->historyPly);
        entry->depth = depth;
        entry->type = type;
        entry->bestMove = bestMove;
    }
}

bool isRepetition(const Board *board) {
    // start 2 plies back (previous time we moved)
    // we stop if we go past the history or past the last irreversible move (halfmoveClock)
    for (int i = 2; i <= board->halfmoveClock && i < board->historyPly; i += 2) {

        // Compare current key with history
        if (board->historyArr[board->historyPly - i].zobristKey == board->zobristKey) {
            return true;
        }
    }
    return false;
}

// --- Search Implementation ---

void initSearch(int timeMs) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    searchInfo.startTime = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    searchInfo.allocatedTime = timeMs;
    searchInfo.timeUp = false;
}

int getElapsedTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long long current = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (int)(current - searchInfo.startTime);
}

bool shouldStop() {
    if (searchInfo.timeUp)
        return true;

    // Check time every 2048 nodes to reduce overhead
    static int checkCounter = 0;
    if ((++checkCounter & 2047) == 0) {
        if (getElapsedTime() >= searchInfo.allocatedTime) {
            searchInfo.timeUp = true;
            return true;
        }
    }
    return false;
}

static uint64_t nodeCount = 0;

// https://www.chessprogramming.org/Quiescence_Search
int quiessence (Board *board, int alpha, int beta) {
    
    if (shouldStop())
        return 0;
    nodeCount++;

    int static_eval = evaluate(board);

    // Stand Pat
    int best_value = static_eval;
    if (best_value >= beta)
        return best_value;

    // delta pruning: test if alpha can be improved by the greatest possible material swing (capturing a queen or promoting a pawn)
    // if we are so below alpha that even capturing a queen/promotion won't help then just return alpha 
    int BIG_DELTA = 900; // Value of a Queen
    enumPiece currSide = board->whiteToMove ? nWhite : nBlack;

    if (canSidePromote(board, currSide)){
        BIG_DELTA+=775 ; // replace pawn with queen 
    }

    if (static_eval < alpha - BIG_DELTA) {
        return alpha;
    }

    if (best_value > alpha)
        alpha = best_value;

    // search every capture to make sure last move didn't put the side in peril
    Move move_list[MAX_MOVES];
    size_t numMoves = 0;
    getPseudoLegalMoves(board, move_list, &numMoves);
    sortMoveList(board, move_list, numMoves); // sort so captures are usually near top


    for (size_t i = 0; i < numMoves; i++) {
        unsigned int flags = getFlags(move_list[i]);

        if (!(isCapture(move_list[i])))
            continue;

        makeMove(board, move_list[i]);

        if (!isSideInCheck(board, currSide)) {
            int score = -quiessence(board, -beta, -alpha);
            unmakeMove(board, move_list[i]);

            if (score >= beta)
                return score;
            if (score > best_value)
                best_value = score;
            if (score > alpha)
                alpha = score;
        } else {

            unmakeMove(board, move_list[i]); // unmake illegal move
        }
    }

    return best_value;
}

int alphaBeta(Board *board, int depth, int alpha, int beta) {
    int alphaOrig = alpha;
    nodeCount++;

    // Periodically check for timeout
    if (shouldStop())
        return 0;

    // Max depth safety check
    if (board->historyPly >= MAX_SEARCH_DEPTH - 1) {
        return quiessence(board, alpha, beta);
    }

    // 50-move rule and if the board state is repeated a draw can be forced 
    if (board->halfmoveClock >= 100 || isRepetition(board)) {
        return DRAW_SCORE;
    }

    
    // 1. Probe Transposition Table
    int ttScore;
    Move ttMove = 0;
    if (probeTransTable(board, depth, alpha, beta, &ttScore, &ttMove)) {
        return ttScore;
    }

    if (depth <= 0) {
        return quiessence(board, alpha, beta);
    }

    // 2. Generate Moves
    Move move_list[MAX_MOVES];
    size_t numMoves = 0;
    getPseudoLegalMoves(board, move_list, &numMoves);

    // 3. Score Moves 
    // We prioritize the move from the TT if it exists
    sortMoveList(board, move_list, numMoves);

    // move tt move to front of list 
    if (ttMove != 0) {
        for (size_t i = 0; i < numMoves; i++) {
            if (move_list[i] == ttMove) { // swap 
                Move temp = move_list[0];
                move_list[0] = ttMove;
                move_list[i] = temp;
                break;
            }
        }
    }

    enumPiece currSide = board->whiteToMove ? nWhite : nBlack;
    size_t legalMoveCount = 0;
    Move bestMove = 0;

    // 4. Iterate Moves
    for (size_t i = 0; i < numMoves; i++) {
        makeMove(board, move_list[i]);

        if (!isSideInCheck(board, currSide)) {
            legalMoveCount++;

            int score = -alphaBeta(board, depth - 1, -beta, -alpha);

            unmakeMove(board, move_list[i]);

            if (searchInfo.timeUp)
                return 0;

            if (score >= beta) {
                // Fail-High (Beta Cutoff)
                storeTransTable(board, depth, beta, TT_BETA, move_list[i]);
                return beta;
            }

            if (score > alpha) {
                // PV-Node (Improved Alpha)
                alpha = score;
                bestMove = move_list[i];
            }
        } else {
            unmakeMove(board, move_list[i]); //unmake illegal move 
        }
    }

    // 5. Checkmate / Stalemate
    if (legalMoveCount == 0) {
        if (isSideInCheck(board, currSide)) {
            // Your format: -MATE + Ply (Absolute score)
            // TT Helper will convert this to stored format automatically
            return -MATE_SCORE + board->historyPly;
        } else {
            return DRAW_SCORE;
        }
    }

    // 6. Store Result
    if (alpha > alphaOrig) {
        storeTransTable(board, depth, alpha, TT_EXACT, bestMove);
    } else {
        storeTransTable(board, depth, alpha, TT_ALPHA, bestMove);
    }

    return alpha;
}

Move getBestMove(Board *board, int maxTimeMs) {
    Move safeMove = 0; // The fallback move
    Move bestMoveThisIter = 0;
    int bestScore = -MATE_SCORE;

    nodeCount = 0;
    initSearch(maxTimeMs);

    // 1. GENERATE A SAFETY FALLBACK MOVE
    // If the search fails completely (0 depth or timeout immediately),
    // we MUST return a legal move to avoid "0000".
    Move moveList[MAX_MOVES];
    size_t numMoves = 0;
    getPseudoLegalMoves(board, moveList, &numMoves);
    enumPiece currSide = board->whiteToMove ? nWhite : nBlack;

    for (size_t i = 0; i < numMoves; i++) {
        makeMove(board, moveList[i]);
        if (!isSideInCheck(board, currSide)) {
            safeMove = moveList[i]; // Found a legal move!
            unmakeMove(board, moveList[i]);
            break;
        }
        unmakeMove(board, moveList[i]);
    }

    // If safeMove is still 0, we are likely Mated or Stalemate.
    

    fprintf(stderr, "Search Start: %dms limit\n", maxTimeMs);

    // Iterative Deepening
    for (int depth = 1; depth <= MAX_SEARCH_DEPTH; depth++) {

        int score = alphaBeta(board, depth, -MATE_SCORE, MATE_SCORE);

        // If time ran out during alphaBeta, the score and TT entry are unreliable.
        // We break immediately and use the result from the PREVIOUS successful depth.
        if (searchInfo.timeUp) {
            fprintf(stderr, "Time Up at Depth %d\n", depth);
            break;
        }

        // Search finished for this depth. Try to retrieve the best move from TT.
        TTEntry *entry = &transTable[board->zobristKey % ttEntryCount];

        // STRICT MOVE VERIFICATION
        // Even if TT says it's best, we verify it is legal in the current position.
        // This prevents "illegal move" bugs caused by hash collisions.
        if (entry->zobristKey == board->zobristKey && entry->bestMove != 0) {
            bool isLegal = false;
            for (size_t i = 0; i < numMoves; i++) {
                if (moveList[i] == entry->bestMove) {
                    makeMove(board, moveList[i]);
                    if (!isSideInCheck(board, currSide)) {
                        isLegal = true;
                    }
                    unmakeMove(board, moveList[i]);
                    break;
                }
            }

            if (isLegal) {
                bestMoveThisIter = entry->bestMove;
                bestScore = score;
                // Update our fallback: this is now the safest, best move we have.
                safeMove = bestMoveThisIter;
            }
        }

        int elapsed = getElapsedTime();
        fprintf(stderr, "Depth %d: Score %d, Nodes %llu, Time %dms\n",
                depth, score, (unsigned long long)nodeCount, elapsed);

        if (score > MATE_BOUND || score < -MATE_BOUND)
            break;
    }

    return safeMove;
}