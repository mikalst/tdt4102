#pragma once

#include <vector>

struct Tile {
    bool open;
    bool mine;
};

class Minesweeper {
private:
    // Legg til de medlemsvariablene og hjelpefunksjonene du trenger
    std::vector<std::vector<int>> grid_values;
    std::vector<std::vector<bool>> grid_open_or_not;
    bool is_game_over;


public:
    Minesweeper(int width, int height, int mines);
    ~Minesweeper();

    bool isGameOver() const;

    bool isTileOpen(int row, int col) const;
    bool isTileMine(int row, int col) const;

    void openTile(int row, int col);

    int numAdjacentMines(int row, int col) const;

    // Vi slår av autogenerert kopikonstruktør og tilordningsoperator for å unngå feil
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};
