#include <iostream>
#include "util.h"
#include "sudoku.h"

int main() {
    std::string inp = ".......3.........6.3.........1..................3.........1.........3.........6..";
    Board board = create_board(inp);

    print_board(board);
    std::cout << solve(board, 0, 0, 0) << std::endl;
}