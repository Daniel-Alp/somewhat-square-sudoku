#include <iostream>
#include "common.h"
#include "helper.h"

int main() {
    std::string inp = ".......2.........5.2.........0..................2.........0.........2.........5..";
    std::array<int32_t, 81> grid;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (inp[i*9+j] == '.') {
                grid[i*9+j] = -1;
            } else {
                grid[i*9+j] = inp[i*9+j] - '0';
            }
        }
    }

    print_grid(grid);
    std::array<uint16_t, 81> candidates = candidates_bitmasks(grid);
    for (size_t sq = 0; sq < 81; sq++) {
        std::cout << "sq " << sq << std::endl;
        print_bitmask(candidates[sq]);
    }
}
