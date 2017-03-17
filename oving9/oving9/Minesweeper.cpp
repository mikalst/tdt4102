#include "Minesweeper.h"

#include <random>
#include <ctime>
#include <iostream>

Minesweeper::Minesweeper(int width, int height, int mines) {
    std::srand(time(NULL));
    this->is_game_over = false;
    
    for (int x = 0; x < height; x++) {
        
        std::vector<int> zero_vector_of_size_n = {0};
        
        for(int x = 1; x < width; x++)
            zero_vector_of_size_n.push_back(0);
        
        for(int n : zero_vector_of_size_n) {
            std::cout << n << '\n';
        }
        
        this->grid_values.push_back(zero_vector_of_size_n);
        // The vector is now filled with zeroes
    }
    
        // Bomb placement, a value of 9 indicates a bomb
    for (int x = 0; x<mines; x++) {
        int width_index = 1 + rand()%(width-2);
        int height_index = 1 + rand()%(height-2);
        
        // Check that chosen random position is not already inhabited by bomb
        while (grid_values.at(height_index).at(width_index) > 8) {
            width_index = 1 + rand()%(width-2);
            height_index = 1 + rand()%(height-2);
        }
        
        // Set bomb indicator
        grid_values.at(height_index).at(width_index) = 9;
            
        // Tell surrounding positions there is now a bomb in adjacent slot
        for (int y = -1; y < 2; y++) {
            grid_values.at(height_index-1).at(width_index + y)++;
            grid_values.at(height_index+1).at(width_index + y)++;
        }
        grid_values.at(height_index).at(width_index - 1)++;
        grid_values.at(height_index).at(width_index + 1)++;
    }
    for (int y = 0; y < height; y++) {
        std::vector<bool> zero_vector_of_size_n(width);
        for(int x = 0; x < width-1; x++) {
            zero_vector_of_size_n.push_back(false);
        }
        this->grid_open_or_not.push_back(zero_vector_of_size_n);
    }
}

Minesweeper::~Minesweeper() {
}

bool Minesweeper::isGameOver() const {
    return this->is_game_over;
}

bool Minesweeper::isTileOpen(int row, int col) const {
    if ((this->grid_open_or_not).at(row).at(col) == true) {
        return true;
    }
    return false;
}

bool Minesweeper::isTileMine(int row, int col) const {
    if ((this->grid_values).at(row).at(col) > 8) {
        return true;
    }
    return false;
}

void Minesweeper::openTile(int row, int col) {
    (this->grid_open_or_not).at(row).at(col) = true;
    // Check if bomb is hit, if so: end game
    if ((this->grid_values).at(row).at(col) > 8) {
        this->is_game_over = true;
    }
}

int Minesweeper::numAdjacentMines(int row, int col) const {
    return (this->grid_values).at(row).at(col) % 9;
}
