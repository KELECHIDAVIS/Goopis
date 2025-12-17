#include "moves.h"
#include "attack_patterns.h"
#include "perft.h"  
int main()
{
    Board board ; 
    initStandardChess(&board); 

    // precompute attack patterns 
    precomputeAllAttacks(); 

    puts("Divide results: "); 
    U64 totalNodes = divide(&board, 2);
    printf("\nTotal Number of Nodes: %llu\n", totalNodes ) ; 
    return 0;
}