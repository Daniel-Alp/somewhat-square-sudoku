#include <iostream>
#include <numeric>
#include "sudoku.h"

int solve(Board& board, int sq, int current_gcd, int max_gcd) {
    // completed a row, calculate new gcd
    if (sq && sq % 9 == 0) {
        current_gcd = std::gcd(current_gcd, row_to_num(board, (sq-1) / 9));

        if (current_gcd <= max_gcd) {
            return max_gcd;
        }

        if (sq == 81) {
            std::cout << "==============================" << std::endl;
            std::cout << current_gcd << std::endl;
            print_board(board);
            return current_gcd;
        }
    }

    if (board.squares[sq] != -1) {
        return solve(board, sq+1, current_gcd, max_gcd);
    }

    int candidates = candidates_bitmask(board, sq);
    for (int val = 0; val < 9; val++) {
        if (candidates & (1 << val)) {
            make_move(board, sq, val);
            max_gcd = std::max(max_gcd, solve(board, sq+1, current_gcd, max_gcd));
            undo_move(board, sq, val);
        }
    }
    return max_gcd;
}