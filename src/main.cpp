#include "util.h"
#include "sudoku.h"

int main() {
    std::string inp = "4...3.......6..8..........1....5..9..8....6...7.2........1.27..5.3....4.9........";
    Board board = create_board(inp);

    print_board(board);
    solve(board, 0);
}