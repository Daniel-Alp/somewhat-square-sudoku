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

void print_board(Board& board);