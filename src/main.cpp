#include <iostream>
#include "util.h"
#include "sudoku.h"

int main() {
    std::string inp = ".......2.........5.2.........0..................2.........0.........2.........5..";
    Board board = create_board(inp, 4);

    print_board(board);
    std::cout << solve(board, 0, 0, 12345678) << std::endl;
}