#include "sudoku.h"

void solve(Board& board, int sq) {
    if (sq == 81) {
        print_board(board);
        return;
    }
    if (board.squares[sq] != -1) {
        solve(board, sq+1);
    }
    int candidates = candidates_bitmask(board, sq);
    for (int val = 0; val < 9; val++) {
        if (candidates & (1 << val)) {
            make_move(board, sq, val);
            solve(board, sq+1);
            undo_move(board, sq, val);
        }
    }
}