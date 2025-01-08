#pragma once
#include "common.h"

uint16_t row_bitmask(std::array<int32_t, 81>& grid, int sq);

uint16_t col_bitmask(std::array<int32_t, 81>& grid, int sq);

uint16_t box_bitmask(std::array<int32_t, 81>& grid, int sq);

std::array<uint16_t, 81> candidates_bitmasks(std::array<int32_t, 81>& grid);

void print_bitmask(uint16_t bitmask);
void print_grid(std::array<int32_t, 81>& grid);