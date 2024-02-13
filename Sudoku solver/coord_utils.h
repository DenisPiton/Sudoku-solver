#pragma once

#include<random>


#include<utility>
#include<vector>

#include"coord.h"

namespace sudoku {

Coord get_next_cell_coord(Coord coord) {

    if (coord.second == GRID_LEN-1 && coord.first == GRID_LEN-1)
        return coord;
    else if (coord.second == GRID_LEN-1)
        return std::make_pair(coord.first+1, 0);
    return std::make_pair(coord.first, coord.second + 1);
}



}  // namespace sudoku


