#include "board.h"
//#include "moves.h"

int main()
{
    puts("File A:\n");
    printBB(FILE_A);

    puts("File B:\n");
    printBB(FILE_B);

    puts("File H:\n");
    printBB(FILE_H);

    puts("File G:\n");
    printBB(FILE_G);

    puts("Rank 1:\n");
    printBB(RANK_1);

    puts("Rank 2:\n");
    printBB(RANK_2);

    puts("Rank 8:\n");
    printBB(RANK_8);

    puts("Rank 7:\n");
    printBB(RANK_7);

    // precomputeKnightAttacks();

    // for (int i = 0; i < 64; i++)
    // {
    //     printf("Knight attacks from %d:\n", i);
    //     printBB(KNIGHT_ATTACK_LOOKUP[i]);
    // }
    // return 0;
}