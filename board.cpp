#include <iostream>
#include <cmath>

#include "board.h"

Board::Board(const std::string & board_play) {
    board = board_play;
    clear_board();
};

void Board::clear_board() {
    for (int col = 0; col < height; col++) {
        for (int row = 0; row < width; row++) {
            if (board[row+(width*col)] == '9') {
                field[row][col] = 9;
            } else {
                field[row][col] = 0;
            }
        }
    }
}


int Board::getwidth() const {
    return width;
}

int Board::getheight() const {
    return height;
}

void Board::setfood() {
    for (int i = 0; i < 1; i++) {
        food_col = rand() % (height - 2) + 1;;
        food_row = rand() % (width - 2) + 1;
        if (field[food_row][food_col] != 9) {
            field[food_row][food_col] = 1;
        } else {
            i--;
        }
    }
}

int Board::getfoodrow() const {
    return food_row;
}

int Board::getfoodcol() const {
    return food_col;
}

int Board::getboardstate(int row, int col) const {
    if (field[row][col] == 9) {
        return 9;
    } else if (field[row][col] == 0) {
        return 0;
    } else if (field[row][col] == 1) {
        return 1;
    } else {
        return -1;
    }
}

void Board::display() {
    for (int col = 0; col < height; col++) {
        for (int row = 0; row < width; row++) {
            if (field[row][col] == 9) {
                std::cout << 'X';
            } else if (field[row][col] == 1) {
                std::cout << 'O';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}
