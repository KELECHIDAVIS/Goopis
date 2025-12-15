#include "attack_patterns.h"
U64 PAWN_ATTACK_LOOKUP[2][64] = {{0x0000000000000200ULL,
                                  0x0000000000000500ULL,
                                  0x0000000000000a00ULL,
                                  0x0000000000001400ULL,
                                  0x0000000000002800ULL,
                                  0x0000000000005000ULL,
                                  0x000000000000a000ULL,
                                  0x0000000000004000ULL,
                                  0x0000000000020000ULL,
                                  0x0000000000050000ULL,
                                  0x00000000000a0000ULL,
                                  0x0000000000140000ULL,
                                  0x0000000000280000ULL,
                                  0x0000000000500000ULL,
                                  0x0000000000a00000ULL,
                                  0x0000000000400000ULL,
                                  0x0000000002000000ULL,
                                  0x0000000005000000ULL,
                                  0x000000000a000000ULL,
                                  0x0000000014000000ULL,
                                  0x0000000028000000ULL,
                                  0x0000000050000000ULL,
                                  0x00000000a0000000ULL,
                                  0x0000000040000000ULL,
                                  0x0000000200000000ULL,
                                  0x0000000500000000ULL,
                                  0x0000000a00000000ULL,
                                  0x0000001400000000ULL,
                                  0x0000002800000000ULL,
                                  0x0000005000000000ULL,
                                  0x000000a000000000ULL,
                                  0x0000004000000000ULL,
                                  0x0000020000000000ULL,
                                  0x0000050000000000ULL,
                                  0x00000a0000000000ULL,
                                  0x0000140000000000ULL,
                                  0x0000280000000000ULL,
                                  0x0000500000000000ULL,
                                  0x0000a00000000000ULL,
                                  0x0000400000000000ULL,
                                  0x0002000000000000ULL,
                                  0x0005000000000000ULL,
                                  0x000a000000000000ULL,
                                  0x0014000000000000ULL,
                                  0x0028000000000000ULL,
                                  0x0050000000000000ULL,
                                  0x00a0000000000000ULL,
                                  0x0040000000000000ULL,
                                  0x0200000000000000ULL,
                                  0x0500000000000000ULL,
                                  0x0a00000000000000ULL,
                                  0x1400000000000000ULL,
                                  0x2800000000000000ULL,
                                  0x5000000000000000ULL,
                                  0xa000000000000000ULL,
                                  0x4000000000000000ULL,
                                  0x0000000000000000ULL,
                                  0x0000000000000000ULL,
                                  0x0000000000000000ULL,
                                  0x0000000000000000ULL,
                                  0x0000000000000000ULL,
                                  0x0000000000000000ULL,
                                  0x0000000000000000ULL,
                                  0x0000000000000000ULL},
                                 {0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000002ULL, 0x0000000000000005ULL, 0x000000000000000aULL, 0x0000000000000014ULL, 0x0000000000000028ULL, 0x0000000000000050ULL, 0x00000000000000a0ULL, 0x0000000000000040ULL, 0x0000000000000200ULL, 0x0000000000000500ULL, 0x0000000000000a00ULL, 0x0000000000001400ULL, 0x0000000000002800ULL, 0x0000000000005000ULL, 0x000000000000a000ULL, 0x0000000000004000ULL, 0x0000000000020000ULL, 0x0000000000050000ULL, 0x00000000000a0000ULL, 0x0000000000140000ULL, 0x0000000000280000ULL, 0x0000000000500000ULL, 0x0000000000a00000ULL, 0x0000000000400000ULL, 0x0000000002000000ULL, 0x0000000005000000ULL, 0x000000000a000000ULL, 0x0000000014000000ULL, 0x0000000028000000ULL, 0x0000000050000000ULL, 0x00000000a0000000ULL, 0x0000000040000000ULL, 0x0000000200000000ULL, 0x0000000500000000ULL, 0x0000000a00000000ULL, 0x0000001400000000ULL, 0x0000002800000000ULL, 0x0000005000000000ULL, 0x000000a000000000ULL, 0x0000004000000000ULL, 0x0000020000000000ULL, 0x0000050000000000ULL, 0x00000a0000000000ULL, 0x0000140000000000ULL, 0x0000280000000000ULL, 0x0000500000000000ULL, 0x0000a00000000000ULL, 0x0000400000000000ULL, 0x0002000000000000ULL, 0x0005000000000000ULL, 0x000a000000000000ULL, 0x0014000000000000ULL, 0x0028000000000000ULL, 0x0050000000000000ULL, 0x00a0000000000000ULL, 0x0040000000000000ULL}};
U64 KNIGHT_ATTACK_LOOKUP[64] = {
    0x0000000000020400ULL,
    0x0000000000050800ULL,
    0x00000000000a1100ULL,
    0x0000000000142200ULL,
    0x0000000000284400ULL,
    0x0000000000508800ULL,
    0x0000000000a01000ULL,
    0x0000000000402000ULL,
    0x0000000002040004ULL,
    0x0000000005080008ULL,
    0x000000000a110011ULL,
    0x0000000014220022ULL,
    0x0000000028440044ULL,
    0x0000000050880088ULL,
    0x00000000a0100010ULL,
    0x0000000040200020ULL,
    0x0000000204000402ULL,
    0x0000000508000805ULL,
    0x0000000a1100110aULL,
    0x0000001422002214ULL,
    0x0000002844004428ULL,
    0x0000005088008850ULL,
    0x000000a0100010a0ULL,
    0x0000004020002040ULL,
    0x0000020400040200ULL,
    0x0000050800080500ULL,
    0x00000a1100110a00ULL,
    0x0000142200221400ULL,
    0x0000284400442800ULL,
    0x0000508800885000ULL,
    0x0000a0100010a000ULL,
    0x0000402000204000ULL,
    0x0002040004020000ULL,
    0x0005080008050000ULL,
    0x000a1100110a0000ULL,
    0x0014220022140000ULL,
    0x0028440044280000ULL,
    0x0050880088500000ULL,
    0x00a0100010a00000ULL,
    0x0040200020400000ULL,
    0x0204000402000000ULL,
    0x0508000805000000ULL,
    0x0a1100110a000000ULL,
    0x1422002214000000ULL,
    0x2844004428000000ULL,
    0x5088008850000000ULL,
    0xa0100010a0000000ULL,
    0x4020002040000000ULL,
    0x0400040200000000ULL,
    0x0800080500000000ULL,
    0x1100110a00000000ULL,
    0x2200221400000000ULL,
    0x4400442800000000ULL,
    0x8800885000000000ULL,
    0x100010a000000000ULL,
    0x2000204000000000ULL,
    0x0004020000000000ULL,
    0x0008050000000000ULL,
    0x00110a0000000000ULL,
    0x0022140000000000ULL,
    0x0044280000000000ULL,
    0x0088500000000000ULL,
    0x0010a00000000000ULL,
    0x0020400000000000ULL};

U64 KING_ATTACK_LOOKUP[64] = {

};

U64 ROOK_ATTACK_LOOKUP[64][4096] = {0ULL};
U64 BISHOP_ATTACK_LOOKUP[64][512] = {0ULL};

SMagic BishopMagicTable[64] = {
    {0x0040201008040200ULL, 0x0022000003240800ULL, 58},
    {0x0000402010080400ULL, 0x0200180040804d01ULL, 59},
    {0x0000004020100a00ULL, 0x0002100002a80014ULL, 59},
    {0x0000000040221400ULL, 0x60403c0006000000ULL, 59},
    {0x0000000002442800ULL, 0x0005040300000800ULL, 59},
    {0x0000000204085000ULL, 0x0000549000001081ULL, 59},
    {0x0000020408102000ULL, 0x2084044000940010ULL, 59},
    {0x0002040810204000ULL, 0x0010001164300001ULL, 58},
    {0x0020100804020000ULL, 0x1008400000073000ULL, 59},
    {0x0040201008040000ULL, 0x0480088001400320ULL, 59},
    {0x00004020100a0000ULL, 0x0000024400420400ULL, 59},
    {0x0000004022140000ULL, 0x0000224001400100ULL, 59},
    {0x0000000244280000ULL, 0x0440130001000000ULL, 59},
    {0x0000020408500000ULL, 0x0000042024002000ULL, 59},
    {0x0002040810200000ULL, 0x0805080948086000ULL, 59},
    {0x0004081020400000ULL, 0x52020220150030e8ULL, 59},
    {0x0010080402000200ULL, 0x10404204004c0040ULL, 59},
    {0x0020100804000400ULL, 0x2102000400444008ULL, 59},
    {0x004020100a000a00ULL, 0x302202001a000000ULL, 57},
    {0x0000402214001400ULL, 0x0486021500c20411ULL, 57},
    {0x0000024428002800ULL, 0x0000020942000002ULL, 57},
    {0x0002040850005000ULL, 0x0a80300540110001ULL, 57},
    {0x0004081020002000ULL, 0x008a000420350004ULL, 59},
    {0x0008102040004000ULL, 0x0024010675001420ULL, 59},
    {0x0008040200020400ULL, 0x0422000030014002ULL, 59},
    {0x0010080400040800ULL, 0x0200022400085b00ULL, 59},
    {0x0020100a000a1000ULL, 0x020b404802000500ULL, 57},
    {0x0040221400142200ULL, 0x4000022000204207ULL, 55},
    {0x0002442800284400ULL, 0x0020220600040042ULL, 55},
    {0x0004085000500800ULL, 0x40020b0045101210ULL, 57},
    {0x0008102000201000ULL, 0x0810411002001000ULL, 59},
    {0x0010204000402000ULL, 0x2260004000250240ULL, 59},
    {0x0004020002040800ULL, 0x280e122009000040ULL, 59},
    {0x0008040004081000ULL, 0x00000a4000205180ULL, 59},
    {0x00100a000a102000ULL, 0x0000220801000088ULL, 57},
    {0x0022140014224000ULL, 0x4200200108200804ULL, 55},
    {0x0044280028440200ULL, 0x0041000400050020ULL, 55},
    {0x0008500050080400ULL, 0x02102534484a2100ULL, 57},
    {0x0010200020100800ULL, 0x6000252041480218ULL, 59},
    {0x0020400040201000ULL, 0x0c0460004142180eULL, 59},
    {0x0002000204081000ULL, 0x0080121800900062ULL, 59},
    {0x0004000408102000ULL, 0x0002090401000000ULL, 59},
    {0x000a000a10204000ULL, 0x00400a8800880220ULL, 57},
    {0x0014001422400000ULL, 0x0000001c40080280ULL, 57},
    {0x0028002844020000ULL, 0x0080628401004010ULL, 57},
    {0x0050005008040200ULL, 0x010c000400a42101ULL, 57},
    {0x0020002010080400ULL, 0x24080e4011011020ULL, 59},
    {0x0040004020100800ULL, 0x0208082008210048ULL, 59},
    {0x0000020408102000ULL, 0x0a003c8008000014ULL, 59},
    {0x0000040810204000ULL, 0x13a0004002610032ULL, 59},
    {0x00000a1020400000ULL, 0x0001000400240000ULL, 59},
    {0x0000142240000000ULL, 0x4210409000c84201ULL, 59},
    {0x0000284402000000ULL, 0x0314020020131120ULL, 59},
    {0x0000500804020000ULL, 0x000c110608000941ULL, 59},
    {0x0000201008040200ULL, 0x3001050020014100ULL, 59},
    {0x0000402010080400ULL, 0x072a010814210004ULL, 59},
    {0x0002040810204000ULL, 0x0000040020403800ULL, 58},
    {0x0004081020400000ULL, 0x4000205004006210ULL, 59},
    {0x000a102040000000ULL, 0x0140308024040090ULL, 59},
    {0x0014224000000000ULL, 0x0280100200282002ULL, 59},
    {0x0028440200000000ULL, 0x0100100418232140ULL, 59},
    {0x0050080402000000ULL, 0x0800406001002080ULL, 59},
    {0x0020100804020000ULL, 0x0008200123000108ULL, 59},
    {0x0040201008040200ULL, 0x0a00008012100260ULL, 58}};

SMagic RookMagicTable[64] = {
    {0x000101010101017eULL, 0x0004208821280304ULL, 52},
    {0x000202020202027cULL, 0x0039008000100050ULL, 53},
    {0x000404040404047aULL, 0x4049040000010840ULL, 53},
    {0x0008080808080876ULL, 0x0014140400912008ULL, 53},
    {0x001010101010106eULL, 0x2080040004204000ULL, 53},
    {0x002020202020205eULL, 0x1125404004100000ULL, 53},
    {0x004040404040403eULL, 0x0820008010040281ULL, 53},
    {0x008080808080807eULL, 0x4408448001400200ULL, 52},
    {0x0001010101017e00ULL, 0x0001004100400000ULL, 53},
    {0x0002020202027c00ULL, 0x00c0000048001560ULL, 54},
    {0x0004040404047a00ULL, 0x0062442400200200ULL, 54},
    {0x0008080808087600ULL, 0x0220328008212032ULL, 54},
    {0x0010101010106e00ULL, 0x4101000400011001ULL, 54},
    {0x0020202020205e00ULL, 0x10000082240040c1ULL, 54},
    {0x0040404040403e00ULL, 0x0001008808421400ULL, 54},
    {0x0080808080807e00ULL, 0x0010081000200200ULL, 53},
    {0x00010101017e0100ULL, 0x401c008010000010ULL, 53},
    {0x00020202027c0200ULL, 0x0848040500003040ULL, 54},
    {0x00040404047a0400ULL, 0x0000400108021020ULL, 54},
    {0x0008080808760800ULL, 0x30c0420e0043000aULL, 54},
    {0x00101010106e1000ULL, 0x2821220201800000ULL, 54},
    {0x00202020205e2000ULL, 0x00005c0100000020ULL, 54},
    {0x00404040403e4000ULL, 0x0800080401120100ULL, 54},
    {0x00808080807e8000ULL, 0x2000402000000000ULL, 53},
    {0x000101017e010100ULL, 0x4004090800800044ULL, 53},
    {0x000202027c020200ULL, 0x050a011400001420ULL, 54},
    {0x000404047a040400ULL, 0x4900160000a00002ULL, 54},
    {0x0008080876080800ULL, 0x4016000228001801ULL, 54},
    {0x001010106e101000ULL, 0x0081001820080002ULL, 54},
    {0x002020205e202000ULL, 0x0240004008000283ULL, 54},
    {0x004040403e404000ULL, 0x7001045000080002ULL, 54},
    {0x008080807e808000ULL, 0x0000001004000002ULL, 53},
    {0x0001017e01010100ULL, 0x00102040040a0000ULL, 53},
    {0x0002027c02020200ULL, 0x0202000030160200ULL, 54},
    {0x0004047a04040400ULL, 0x0001102021001000ULL, 54},
    {0x0008087608080800ULL, 0x0000104202000024ULL, 54},
    {0x0010106e10101000ULL, 0x000018a0040100b1ULL, 54},
    {0x0020205e20202000ULL, 0x0020000050080210ULL, 54},
    {0x0040403e40404000ULL, 0x0050000126000180ULL, 54},
    {0x0080807e80808000ULL, 0x0000000004040002ULL, 53},
    {0x00017e0101010100ULL, 0x00200002417a4004ULL, 53},
    {0x00027c0202020200ULL, 0x0120000001241820ULL, 54},
    {0x00047a0404040400ULL, 0x0002040200002000ULL, 54},
    {0x0008760808080800ULL, 0x0064040a0a000380ULL, 54},
    {0x00106e1010101000ULL, 0x2000000000201140ULL, 54},
    {0x00205e2020202000ULL, 0x0002100600280824ULL, 54},
    {0x00403e4040404000ULL, 0x6041000c12100011ULL, 54},
    {0x00807e8080808000ULL, 0x66c4102000420410ULL, 53},
    {0x007e010101010100ULL, 0x2003080000001800ULL, 53},
    {0x007c020202020200ULL, 0x2000056100020060ULL, 54},
    {0x007a040404040400ULL, 0x000440400c401428ULL, 54},
    {0x0076080808080800ULL, 0x008004014a400080ULL, 54},
    {0x006e101010101000ULL, 0x0002008001800120ULL, 54},
    {0x005e202020202000ULL, 0x00001081022c0000ULL, 54},
    {0x003e404040404000ULL, 0x2024000600004248ULL, 54},
    {0x007e808080808000ULL, 0x1100020000000c01ULL, 53},
    {0x7e01010101010100ULL, 0x000600a005100000ULL, 52},
    {0x7c02020202020200ULL, 0x40000c1840080180ULL, 53},
    {0x7a04040404040400ULL, 0x002004a240000008ULL, 53},
    {0x7608080808080800ULL, 0x0840000003022c83ULL, 53},
    {0x6e10101010101000ULL, 0x0b84000204000809ULL, 53},
    {0x5e20202020202000ULL, 0x2049000300003804ULL, 53},
    {0x3e40404040404000ULL, 0x0084096102314120ULL, 53},
    {0x7e80808080808000ULL, 0x1004040a2a010480ULL, 52}};

int RBits[64] = {
    12, 11, 11, 11, 11, 11, 11, 12,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    12, 11, 11, 11, 11, 11, 11, 12};

int BBits[64] = {
    6, 5, 5, 5, 5, 5, 5, 6,
    5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 7, 7, 7, 7, 5, 5,
    5, 5, 7, 9, 9, 7, 5, 5,
    5, 5, 7, 9, 9, 7, 5, 5,
    5, 5, 7, 7, 7, 7, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5,
    6, 5, 5, 5, 5, 5, 5, 6};

U64 noNoEa(U64 b) { return (b << 17) & ~FILE_A; }
U64 noEaEa(U64 b) { return (b << 10) & ~(FILE_A | FILE_B); }
U64 soEaEa(U64 b) { return (b >> 6) & ~(FILE_A | FILE_B); }
U64 soSoEa(U64 b) { return (b >> 15) & ~FILE_A; }
U64 noNoWe(U64 b) { return (b << 15) & ~FILE_H; }
U64 noWeWe(U64 b) { return (b << 6) & ~(FILE_G | FILE_H); }
U64 soWeWe(U64 b) { return (b >> 10) & ~(FILE_G | FILE_H); }
U64 soSoWe(U64 b) { return (b >> 17) & ~FILE_H; }
U64 north(U64 b) { return (b << 8) & ~RANK_1; }
U64 south(U64 b) { return (b >> 8) & ~RANK_8; }
U64 east(U64 b) { return (b << 1) & ~FILE_A; }
U64 west(U64 b) { return (b >> 1) & ~FILE_H; }
U64 northEast(U64 b) { return (b << 9) & ~RANK_1 & ~FILE_A; }
U64 southEast(U64 b) { return (b >> 7) & ~RANK_8 & ~FILE_A; }
U64 northWest(U64 b) { return (b << 7) & ~FILE_H & ~RANK_1; }
U64 southWest(U64 b) { return (b >> 9) & ~FILE_H & ~RANK_8; }

// precompute all attacks and save them to 
void precomputeAllAttacks(void)
{
}

//TODO: make pawn, king, and knight precompute functions write to file for copying 
void precomputePawnAttacks()
{
    for (int i = nWhite; i <= nBlack; i++) // for both colors
    {
        for (int square = 0; square < 64; square++)
        {
            U64 attacks = 0ULL;
            U64 position = 1ULL << square;

            if (i == nWhite)
            {
                // white pawns attack diagonally up
                if ((position << 7) & ~FILE_H)
                    attacks |= (position << 7); // up-right
                if ((position << 9) & ~FILE_A)
                    attacks |= (position << 9); // up-left
            }
            else
            {
                // black pawns attack diagonally down
                if ((position >> 7) & ~FILE_A)
                    attacks |= (position >> 7); // down-left
                if ((position >> 9) & ~FILE_H)
                    attacks |= (position >> 9); // down-right
            }
            PAWN_ATTACK_LOOKUP[i][square] = attacks;
        }
    }
}

void precomputeKingAttacks(void)
{
    for (int square = 0; square < 64; square++)
    {
        // add all possible king  moves from this square
        U64 attacks = 0ULL;
        U64 position = 1ULL << square;
        attacks |= north(position);
        attacks |= south(position);
        attacks |= east(position);
        attacks |= west(position);
        attacks |= northEast(position);
        attacks |= southEast(position);
        attacks |= northWest(position);
        attacks |= southWest(position);

        KING_ATTACK_LOOKUP[square] = attacks;
    }
}

void precomputeKnightAttacks()
{
    for (int square = 0; square < 64; square++)
    {
        // add all possible knight moves from this square
        U64 attacks = 0ULL;
        U64 position = 1ULL << square;
        attacks |= noNoEa(position); // up-right
        attacks |= noEaEa(position); // up-left
        attacks |= soEaEa(position); // down-left
        attacks |= soSoEa(position); // down-right
        attacks |= noNoWe(position); // up-left
        attacks |= noWeWe(position); // up-right
        attacks |= soWeWe(position); // down-right
        attacks |= soSoWe(position); // down-left

        KNIGHT_ATTACK_LOOKUP[square] = attacks;
    }
}

// precomputes the relevant blocking squares for each square (code from:https://www.chessprogramming.org/Looking_for_Magics )
void precomputeRookMasks()
{
    for (int sq = 0; sq < 64; sq++)
    {
        U64 result = 0ULL;
        int rk = sq / 8, fl = sq % 8, r, f;
        for (r = rk + 1; r <= 6; r++)
            result |= (1ULL << (fl + r * 8));
        for (r = rk - 1; r >= 1; r--)
            result |= (1ULL << (fl + r * 8));
        for (f = fl + 1; f <= 6; f++)
            result |= (1ULL << (f + rk * 8));
        for (f = fl - 1; f >= 1; f--)
            result |= (1ULL << (f + rk * 8));

        RookMagicTable[sq].mask = result;
    }
}
void precomputeBishopMasks()
{
    for (int sq = 0; sq < 64; sq++)
    {
        U64 result = 0ULL;
        int rk = sq / 8, fl = sq % 8, r, f;
        for (r = rk + 1, f = fl + 1; r <= 6 && f <= 6; r++, f++)
            result |= (1ULL << (f + r * 8));
        for (r = rk + 1, f = fl - 1; r <= 6 && f >= 1; r++, f--)
            result |= (1ULL << (f + r * 8));
        for (r = rk - 1, f = fl + 1; r >= 1 && f <= 6; r--, f++)
            result |= (1ULL << (f + r * 8));
        for (r = rk - 1, f = fl - 1; r >= 1 && f >= 1; r--, f--)
            result |= (1ULL << (f + r * 8));

        BishopMagicTable[sq].mask = result;
    }
}


U64 iterative_getBishopAttackPattern(U64 block, enumSquare sq)
{
    U64 result = 0ULL;
    int rk = (int)sq / 8, fl = (int)sq % 8, r, f;
    for (r = rk + 1, f = fl + 1; r <= 7 && f <= 7; r++, f++)
    {
        result |= (1ULL << (f + r * 8));
        if (block & (1ULL << (f + r * 8)))
            break;
    }
    for (r = rk + 1, f = fl - 1; r <= 7 && f >= 0; r++, f--)
    {
        result |= (1ULL << (f + r * 8));
        if (block & (1ULL << (f + r * 8)))
            break;
    }
    for (r = rk - 1, f = fl + 1; r >= 0 && f <= 7; r--, f++)
    {
        result |= (1ULL << (f + r * 8));
        if (block & (1ULL << (f + r * 8)))
            break;
    }
    for (r = rk - 1, f = fl - 1; r >= 0 && f >= 0; r--, f--)
    {
        result |= (1ULL << (f + r * 8));
        if (block & (1ULL << (f + r * 8)))
            break;
    }
    return result;
}
U64 iterative_getRookAttackPattern(U64 block, enumSquare sq)
{
    U64 result = 0ULL;
    int rk = (int)sq / 8, fl = (int)sq % 8, r, f;
    for (r = rk + 1; r <= 7; r++)
    {
        result |= (1ULL << (fl + r * 8));
        if (block & (1ULL << (fl + r * 8)))
            break;
    }
    for (r = rk - 1; r >= 0; r--)
    {
        result |= (1ULL << (fl + r * 8));
        if (block & (1ULL << (fl + r * 8)))
            break;
    }
    for (f = fl + 1; f <= 7; f++)
    {
        result |= (1ULL << (f + rk * 8));
        if (block & (1ULL << (f + rk * 8)))
            break;
    }
    for (f = fl - 1; f >= 0; f--)
    {
        result |= (1ULL << (f + rk * 8));
        if (block & (1ULL << (f + rk * 8)))
            break;
    }
    return result;
}
// Extract the position of the least significant set bit and clear it from the bitboard
int popLeastSignificantBit(U64 *bitboard)
{
    if (*bitboard == 0)
        return -1; // Handle empty bitboard

    // Find the index of the least significant bit using built-in function
    int bitIndex = __builtin_ctzll(*bitboard); // Count trailing zeros

    // Clear that bit from the bitboard
    *bitboard &= (*bitboard - 1);

    return bitIndex;
}

U64 createBlockerConfig(int blockerIndex, int numBitsInMask, U64 mask){
    U64 result =0; 
    for(int i =0; i< numBitsInMask; i++){
        int index = popLeastSignificantBit(&mask);
        if (blockerIndex & (1 << i))
        {
            result |= (1ULL << index)   ;
        }
    }
    return result; 
}

// find magic numbers through trial and error
// based on this code: https://www.chessprogramming.org/Looking_for_Magics
U64 findMagicNum(bool isBishop, enumSquare square)
{
    U64 mask = isBishop ? BishopMagicTable[square].mask : RookMagicTable[square].mask;
    assert(mask != 0 && "Masks weren't initialized prior to calling the findMagicNum function.");

    U64 blockerConfigs[4096];
    U64 attackPatterns[4096];
    U64 hashTable[4096];
    U64 magicNumber;
    int numConfigs, numBitsInMask;

    numBitsInMask = __builtin_popcountll(mask);
    numConfigs = 1 << numBitsInMask;

    // Generate all blocker configurations and attack patterns
    for (int i = 0; i < numConfigs; i++)
    {
        blockerConfigs[i] = createBlockerConfig(i, numBitsInMask, mask);
        attackPatterns[i] = isBishop ? iterative_getBishopAttackPattern(blockerConfigs[i], square) : iterative_getRookAttackPattern(blockerConfigs[i], square);
    }

    int shiftAmt = 64 - numBitsInMask;

    // Try random magic numbers
    for (int z = 0; z < 100000000; z++)
    {
        magicNumber = randU64() & randU64() & randU64();

        // Skip if not enough bits in upper byte
        int numSetBits = __builtin_popcountll((mask * magicNumber) & 0xFF00000000000000ULL);
        if (numSetBits < 6)
            continue;

        // Clear hash table
        memset(hashTable, 0, sizeof(hashTable));

        // Test this magic number
        bool fail = false;
        for (int i = 0; i < numConfigs && !fail; i++)
        {
            int hashIndex = (int)((blockerConfigs[i] * magicNumber) >> shiftAmt);

            if (hashTable[hashIndex] == 0ULL)
            {
                hashTable[hashIndex] = attackPatterns[i];
            }
            else if (hashTable[hashIndex] != attackPatterns[i])
            {
                fail = true; // Non-constructive collision
            }
        }

        // If no collisions, we found a valid magic!
        if (!fail)
        {
            return magicNumber;
        }
    }

    // Failed to find magic after all attempts
    printf("Magic generation for square %d (%s) failed after 100000000 attempts.\n",
           square, isBishop ? "Bishop" : "Rook");
    return 0;
}
void printPawnAttacks()
{
    for (int i = nWhite; i <= nBlack; i++) // for both colors
    {
        for (int square = 0; square < 64; square++)
        {
            printf("Pawn attacks for %s from square %d:\n", i == nWhite ? "White" : "Black", square);
            printBB(PAWN_ATTACK_LOOKUP[i][square]);
        }
    }
}




void printKnightAttacks()
{
    for (int square = 0; square < 64; square++)
    {
        printf("Knight attacks from square %d:\n", square);
        printBB(KNIGHT_ATTACK_LOOKUP[square]);
    }
}

void precomputeMagicNumbersAndSaveToFile(){

    // Generate Bishop Magic Numbers
    printf("Generating Bishop Magic Numbers...\n");
    precomputeBishopMasks();

    FILE *fp = fopen("bishop_magic_structs.txt", "w");
    if (!fp)
    {
        fprintf(stderr, "Error: Could not open bishop_magic_structs.txt for writing\n");
        abort();
    }

    fprintf(fp, "{\n");
    for (int square = 0; square < 64; square++)
    {
        int bitsSet = __builtin_popcountll(BishopMagicTable[square].mask);
        int shiftAmt = 64 - bitsSet;
        U64 magic =  findMagicNum(true, square);

        
        printf("Square %2d: { 0x%016llx, 0x%016llx, %d }\n",
               square, BishopMagicTable[square].mask,
               magic ,
               shiftAmt);

        if (magic == 0)
        {
            printf("Magic Generation failed, Returned magic number was zero"); 
            abort(); 
        }

        fprintf(fp, "    { 0x%016llxULL, 0x%016llxULL, %d }%s\n",
                BishopMagicTable[square].mask,
                magic,
                shiftAmt,
                square < 63 ? "," : "");
    }
    fprintf(fp, "};\n");
    fclose(fp);
    printf("Bishop magic numbers saved to bishop_magic_structs.txt\n\n");

    // Generate Rook Magic Numbers
    printf("Generating Rook Magic Numbers...\n");
    precomputeRookMasks();

    FILE *fp2 = fopen("rook_magic_structs.txt", "w");
    if (!fp2)
    {
        fprintf(stderr, "Error: Could not open rook_magic_structs.txt for writing\n");
        abort();
    }

    fprintf(fp2, "{\n");
    for (int square = 0; square < 64; square++)
    {
        int bitsSet = __builtin_popcountll(RookMagicTable[square].mask);
        int shiftAmt = 64 - bitsSet;
        U64 magic = findMagicNum(false, square);

        printf("Square %2d: { 0x%016llx, 0x%016llx, %d }\n",
               square, RookMagicTable[square].mask,
               magic,
               shiftAmt);

        if (magic == 0)
        {
            printf("Magic Generation failed, Returned magic number was zero");
            abort();
        }
        fprintf(fp2, "    { 0x%016llxULL, 0x%016llxULL, %d }%s\n",
                RookMagicTable[square].mask,
                magic,
                shiftAmt,
                square < 63 ? "," : "");
    }
    fprintf(fp2, "};\n");
    fclose(fp2);
    printf("Rook magic numbers saved to rook_magic_structs.txt\n");
}

// call this function after magic number have been precomputed and copy and pasted into the smagic tables 
void precomputeSlidingPieceLookupTablesAndSaveToFile(){
    //first rook then bishop  
    for(int isBishop=0; isBishop <=1; isBishop++){
        for (int square = 0; square < 64; square++)
        {
            SMagic entry = isBishop ? BishopMagicTable[square] : RookMagicTable[square];
            U64 mask = entry.mask; 

            int numConfigs,  numBitsInMask;

            numBitsInMask = __builtin_popcountll(mask);
            numConfigs = 1 << numBitsInMask; // 2^numBits;

            
            // for each blocker config, iteratively get the attack pattern for it
            for (int i = 0; i < numConfigs; i++)
            {
                U64 blockers = createBlockerConfig(i, numBitsInMask, mask);
                U64 attackPattern = isBishop ? iterative_getBishopAttackPattern(blockers, square) : iterative_getRookAttackPattern(blockers, square);
                
                int hashIndex =magicIndex(&entry, blockers);

                printf("Hash Index %d\n", hashIndex);
                printf("Blocker Config %d: \n", i);
                printBB(blockers);
                puts("Attack Pattern");
                printBB(attackPattern);

                // check for non constructive collisions 
                U64 *hashTable = isBishop ? BISHOP_ATTACK_LOOKUP[square] : ROOK_ATTACK_LOOKUP[square];  

                if(hashTable[hashIndex] == 0ULL){
                    hashTable[hashIndex] = attackPattern; 
                }else if (hashTable[hashIndex] != attackPattern){ // Non Constructive collsion
                    printf("Non Constructive Collision occured in %s initialization in Square %d \n", 
                        isBishop ? "Bishop" : "Rook"   ,
                        square
                    ); 
                    printf("Hash Index %d\n", hashIndex); 
                    printf("Blocker Config %d: \n", i); 
                    printBB(blockers)   ; 
                    puts("Attack Pattern"); 
                    printBB(attackPattern); 

                    puts("Closing Program ..."); 
                    abort(); 

                }
            }

        }
    }
    
}
