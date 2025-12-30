#ifndef SEARCH_H
#define SEARCH_H
#include "eval.h"
#include "moves.h"
#include <float.h>

#include <stdbool.h>
#include <time.h>

#define DRAW_SCORE 0
#define MATE_SCORE 100000

typedef struct {
    clock_t startTime;
    int allocatedTime; // in milliseconds
    bool timeUp;
} SearchInfo;

extern SearchInfo searchInfo; // Global search info

// Helper functions
void initSearch(int timeMs);
bool shouldStop();
int getElapsedTime();
extern double alphaBeta(Board* board, int depth , double alpha , double beta); 

extern Move getBestMove(Board* board, int depth ); 
#endif //  SEARCH_H