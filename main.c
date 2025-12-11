#include "board.h"

int main(){

    char fen[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"; 

    Board board;
    initBoard(&board, fen );

    const char s[2] = " ";                   // Delimiter is a space
    char *token;                             // Pointer to individual token

    // Get the first token
    token = strtok(fen, s);

    // Walk through other tokens
    while (token != NULL) {
        printf(" %s\n", token); // Print the token
        token = strtok(NULL, s); // Get the next token by passing NULL
    }
    return 0;
}