#ifndef SRC_GRID_H_
#define SRC_GRID_H_

#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include"coord.h"

namespace sudoku {

class Grid {
   
    private:
    std::array<std::array<int, 9>, 9> grid;
    std::set<Coord> coords_that_were_pre_filled;

    public:
    Grid() {
        std::array<int, 9> filled_array = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        grid.fill(filled_array);
    }

    explicit Grid(std::array<std::array<int, 9>, 9> grid) {
        set_initial_state(grid);
    }

    

    void set_initial_state(std::array<std::array<int, 9>, 9> grid) {
        
        coords_that_were_pre_filled.clear();

        for (int row = 0; row < GRID_LEN; row++) {
            for (int col = 0; col < GRID_LEN; col++) {
                int cell_value = grid.at(row).at(col);

                if (cell_value < 0 || cell_value > 9) {
                    throw std::invalid_argument(
                        "Cell value should be in range 0 <= x <= 9");
                }

                this->grid.at(row).at(col) = cell_value;
                if (cell_value == 0) continue;
                coords_that_were_pre_filled.insert(std::make_pair(row, col));
            }
        }
    }

    void set_initial_state_from_file(std::string filename) {

        std::ifstream file;
        file.open(filename, std::ios::in);
        if (file.fail()) throw std::invalid_argument(
            "The file couldn't be opened. Please check if the file exists.");

        std::array<std::array<int, 9>, 9> grid;

        for (int row_index = 0; row_index < GRID_LEN; row_index++) {
            for (int col_index = 0; col_index < GRID_LEN; col_index++) {
                file >> grid.at(row_index).at(col_index);
                if (file.eof()) throw std::invalid_argument(
                    "Too little values provided. Please supply 81 values.");
            }
        }

        int value;
        file >> value;
        if (!file.eof()) throw std::invalid_argument(
            "Too many values provided. Please supply only 81 values.");

        file.close();
        set_initial_state(grid);
    }

    void update(Coord coord, int value) {
        if (value < 0 || value > 9) throw std::invalid_argument(
            "Cell value should be in range 0 <= x <= 9");
        grid.at(coord.first).at(coord.second) = value;
    }

    int get(Coord coord) const {
        return grid.at(coord.first).at(coord.second);
    }

    void clear_values_starting_from_coord(Coord coord) {
        for (int row = coord.first; row < GRID_LEN; row++) {
            for (int col = coord.second; col < GRID_LEN; col++) {
                auto pos_in_pre_filled = std::find(
                    coords_that_were_pre_filled.begin(),
                    coords_that_were_pre_filled.end(),
                    coord);
                if (pos_in_pre_filled == coords_that_were_pre_filled.end()) {
                    grid.at(coord.first).at(coord.second) = 0;
                }
            }
        }
    }



    bool value_exists_elsewhere_in_column(Coord coord, int value) const {
        
		bool trigger = false;
        for (int i = 0; i < 9; i++)
        {
            if(grid[i][coord.second]==value && Coord(i,coord.second)!=coord)
			{
				trigger = true;
			}
			

        }
		return trigger;

        
    }

    bool value_exists_elsewhere_in_row(Coord coord, int value) const {
		bool trigger = false;
        for (int i= 0 ; i < 9; i++)
        {
            if (grid[coord.first][i] == value && Coord(coord.first, i) != coord)
            {
				trigger = true;
                    
            }
        }
		return trigger;
    }

    bool value_exists_elsewhere_in_3x3_grid(Coord coord, int value) const {
        int row_start = (coord.first/3)*3;
        int row_end = (row_start+2);

        int col_start = (coord.second/3)*3;
        int col_end = (col_start+2);

        for (int row_iter=row_start; row_iter <= row_end; row_iter++) {
            for (int col_iter = col_start; col_iter <= col_end; col_iter++) {

                bool coord_diff_to_given_coord =
                    std::make_pair(row_iter, col_iter) != coord;
                if (coord_diff_to_given_coord &&
                    (grid.at(row_iter).at(col_iter) == value)) return true;
            }
        }

        return false;
    }

    bool coord_was_pre_filled(Coord coord) const {
        auto element_found = std::find(
            coords_that_were_pre_filled.begin(),
            coords_that_were_pre_filled.end(),
            coord);

        return (element_found != coords_that_were_pre_filled.end());
    }


    std::vector<int> get_possible_values_for_cell_at_coord(Coord coord) {
        std::vector<int> values{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        std::vector<int> filtered_values(values.size());
        
        /*for (int i : values) 
        {
			if(value_exists_elsewhere_in_column(coord, i) ||
				value_exists_elsewhere_in_row(coord, i) ||
				value_exists_elsewhere_in_3x3_grid(coord, i))
				{
					values.erase(std::remove(values.begin(), values.end(), i), values.end());
			}
        }
        return values;*/
        auto it = std::copy_if(
            values.begin(), values.end(),
            filtered_values.begin(),
            [this, coord] (int value) -> bool {
                return !(
                    this->value_exists_elsewhere_in_column(coord, value) ||
                    this->value_exists_elsewhere_in_row(coord, value) ||
                    this->value_exists_elsewhere_in_3x3_grid(coord, value));
            });

        filtered_values.resize(std::distance(filtered_values.begin(), it));
        return filtered_values;

    }


    bool operator== (const Grid& grid) const {
        for (int row = 0; row < GRID_LEN; row++) {
            for (int col = 0; col < GRID_LEN; col++) {
                auto coord = std::make_pair(row, col);
                if (get(coord) != grid.get(coord)) return false;
            }
        }
        return true;
    }
    
    friend std::ostream& operator<< (std::ostream& out, Grid grid);
};

std::ostream& operator<< (std::ostream& out, Grid grid) {
    out << "+-------+-------+-------+\n";
    for (int row_index=0; row_index < GRID_LEN; row_index++) {
        out << "|";
        for (int col_index=0; col_index < GRID_LEN; col_index++) {
            out << " " << grid.grid[row_index][col_index];
            if (col_index%3 == 2) out << " |";
        }
        out << "\n";
        if (row_index%3 == 2) out << "+-------+-------+-------+\n";
    }
    return out;
}

}  

#endif