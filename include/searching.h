#ifndef SEARCH_H
#define SEARCH_H
#include "eval.h"
#include "moves.h"
#include <float.h>

#define DRAW_SCORE 0
#define MATE_SCORE 100000
extern double alphaBeta(Board* board, int depth , double alpha , double beta); 

extern Move getBestMove(Board* board, int depth ); 
#endif //  SEARCH_H