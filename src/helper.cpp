#include <iostream>
#include "helper.h"

uint16_t row_bitmask(std::array<int32_t, 81>& grid, int sq) {
    uint16_t bitmask = 0;
    int r = sq / 9;
    for(int i = 0; i < 9; i++) {
        if (grid[r*9+i] == -1) {
            continue;
        }
        bitmask |= 1 << grid[r*9+i];
    }
    return bitmask;
}

uint16_t col_bitmask(std::array<int32_t, 81>& grid, int sq) {
    uint16_t bitmask = 0;
    int c = sq % 9;
    for(int i = 0; i < 9; i++) {
        if (grid[i*9+c] == -1) {
            continue;
        }
        bitmask |= 1 << grid[i*9+c];
    }
    return bitmask;
}

uint16_t box_bitmask(std::array<int32_t, 81>& grid, int sq) {
    uint16_t bitmask = 0;
    int r_box = ((sq / 9) / 3) * 3;
    int c_box = ((sq % 9) / 3) * 3;
    for(int i = r_box; i < r_box + 3; i++) {
        for(int j = c_box; j < c_box + 3; j++) {
            bitmask |= 1 << grid[i*9+j];
        }
    }
    return bitmask;
}

std::array<uint16_t, 81> candidates_bitmasks(std::array<int32_t, 81>& grid) {
    std::array<uint16_t, 81> candidates;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {            
            int sq = i*9+j;
            if (grid[sq] != -1) {
                candidates[sq] = 0;
            } else {
                candidates[sq] = ((1 << 10) - 1) & ~(row_bitmask(grid, sq) | col_bitmask(grid, sq) | box_bitmask(grid, sq));
            }
        }
    }
    return candidates;
}


void print_bitmask(uint16_t bitmask) {
    for (int i = 0; i < 11; i++) {
        if (bitmask & (1 << i)) {
            std::cout << i << std::endl;
        }
    }
    std::cout << std::endl;
}

void print_grid(std::array<int32_t, 81>& grid) {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (grid[i*9+j] == -1) {
                std::cout << '.';
            } else {
                std::cout << grid[i*9+j];
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}