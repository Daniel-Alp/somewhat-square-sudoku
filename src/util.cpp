#include <iostream>
#include "util.h"

Board create_board(std::string& inp) {
    Board board{};
    for (int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            int sq = i*9+j;
            if (inp[sq] == '.') {
                board.squares[sq] = -1;
            } else {
                int val = inp[sq] - '1';
                board.squares[sq] = inp[sq] - '1';
                board.rows[i] |= 1 << val;
                board.cols[j] |= 1 << val;
                board.boxes[(i/3)*3 + j/3] |= 1 << val;
            }
        }
    }

    return board;
}

int candidates_bitmask(Board& board, int sq) {
    if (board.squares[sq] != -1) {
        return 0;
    }
    int bitmask = (1 << 9) - 1;
    int r = sq / 9;
    int c = sq % 9;
    int b = (r/3)*3 + (c/3);
    bitmask &= ~(board.rows[r] | board.cols[c] | board.boxes[b]);
    return bitmask;
}

void make_move(Board& board, int sq, int val) {
    int r = sq / 9;
    int c = sq % 9;
    int b = (r/3)*3 + (c/3);
    board.rows[r] |= 1 << val;
    board.cols[c] |= 1 << val;
    board.boxes[b] |= 1 << val;
    board.squares[sq] = val;
} 

void undo_move(Board& board, int sq, int val) {
    int r = sq / 9;
    int c = sq % 9;
    int b = (r/3)*3 + (c/3);
    board.rows[r] &= ~(1 << val);
    board.cols[c] &= ~(1 << val);
    board.boxes[b] &= ~(1 << val);
    board.squares[sq] = -1;
} 

int row_to_num(Board& board, int r) {
    int n = 0;
    for(int i = 0; i < 9; i++) {
        n *= 10;
        n += board.squares[r*9+i];
    }
    return n;
}

void print_board(Board& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int sq = i*9+j;
            if (board.squares[sq] == -1) {
                std::cout << '.';
            } else {
                std::cout << board.squares[sq];
            }
        }
        std::cout << std::endl;
    }
}