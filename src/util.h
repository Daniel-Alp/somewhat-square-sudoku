#pragma once
#include <string>
#include "common.h"

struct Board {
    std::array<int, 81> squares;
    std::array<int, 9> rows;
    std::array<int, 9> cols;
    std::array<int, 9> boxes;
};

Board create_board(std::string& inp);

int candidates_bitmask(Board& board, int sq);

void make_move(Board& board, int sq, int val);

void undo_move(Board& board, int sq, int val);

int row_to_num(Board& board, int r);

void print_board(Board& board);