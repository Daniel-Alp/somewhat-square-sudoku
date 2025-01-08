#include <iostream>
#include "util.h"

Board create_board(std::string& inp) {
    Board board{};
    for (int i = 0; i < 9; i++) {
        board.rows[i] = (1 << 9) - 1;
        board.cols[i] = (1 << 9) - 1;
        board.boxes[i] = (1 << 9) - 1;
    }

    for (int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            int sq = i*9+j;
            if (inp[sq] == '.') {
                board.squares[sq] = -1;
            } else {
                int val = inp[sq] - '1';
                board.squares[sq] = inp[sq] - '1';
                board.rows[i] &= ~(1 << val);
                board.cols[j] &= ~(1 << val);
                board.boxes[(i/3)*3 + j/3] &= ~(1 << val);
            }
        }
    }

    return board;
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
    std::cout << std::endl;
}