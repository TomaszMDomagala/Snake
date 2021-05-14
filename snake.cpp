#include <iostream>
#include "snake.h"

Snake::Snake(Board & board) : board(board) {
    for (int cubie = 0; cubie < 4; cubie++) {
        cubies startpart;
        startpart.xpos = 10 + cubie;
        startpart.ypos = 15;
        startpart.xdir = -1;
        startpart.ydir = 0;
        parts.push_back(startpart);
    }
    board.setfood();
}

bool Snake::isSnake(int x, int y) {
    for (int xp = 0; xp < parts.size(); xp++) {
        if (parts[xp].xpos == x && parts[xp].ypos == y) {
            return true;
        }
    }
    return false;
}

void Snake::display() {
    for (int col = 0; col < board.getwidth(); col++) {
        for (int row = 0; row < board.getheight(); row++) {
            if (isSnake(row, col) == true) {
                std::cout << "#";
            } else if (board.getboardstate(row, col) == 1) {
                std::cout << "O";
            } else if (board.getboardstate(row, col) == 9) {
                std::cout << "X";
            } else {
                std::cout << " ";
            }
        }
        std::cout << '\n';
    }
}

void Snake::move() {
    if (running == false) {
        return;
    }

    for (int moves = 0; moves < parts.size(); moves++) {
        if (parts[moves].xdir == 1) {
            parts[moves].xpos += 1;
        } else if (parts[moves].xdir == -1) {
            parts[moves].xpos -= 1;
        } else if (parts[moves].ydir == 1) {
            parts[moves].ypos += 1;
        } else if (parts[moves].ydir == -1) {
            parts[moves].ypos -= 1;
        } else {
            break;
        }

        if (moves > 0) {
            if (parts[moves - 1].xdir == 0 && parts[moves - 1].ypos != parts[moves].ypos) {
                parts[moves].ydir = parts[moves - 1].ydir;
                parts[moves].xdir = parts[moves - 1].xdir;
            } else if (parts[moves - 1].ydir == 0 && parts[moves - 1].xpos != parts[moves].xpos) {
                parts[moves].ydir = parts[moves - 1].ydir;
                parts[moves].xdir = parts[moves - 1].xdir;
            }
        }
    }
}

void Snake::turn(int side) {
    if (side == 1) {
        if (parts[0].ydir != -1) {
            parts[0].xdir = 0;
            parts[0].ydir = 1;
        }
    }
    if (side == 2) {
        if (parts[0].ydir != 1) {
            parts[0].xdir = 0;
            parts[0].ydir = -1;
        }
    }
    if (side == 3) {
        if (parts[0].xdir != -1) {
            parts[0].xdir = 1;
            parts[0].ydir = 0;
        }
    }
    if (side == 4) {
        if (parts[0].xdir != 1) {
            parts[0].xdir = -1;
            parts[0].ydir = 0;
        }
    }
}

void Snake::collision() {
    int posx = parts[0].xpos, posy = parts[0].ypos, size = (parts.size() - 1);

    //checking collisions with walls (9 is wall)
    if (board.getboardstate(posx, posy) == 9) {
        running = false;
    }
    //checking if snake didn't eat himself
    for (int cubie = 1; cubie < parts.size(); cubie++) {
        if (posx == parts[cubie].xpos && posy == parts[cubie].ypos) {
            running = false;
        }
    }
    //checking if snake ate his food (1 is food)
    if (board.getboardstate(posx, posy) == 1) {
        miliseconds -= 5;
        score += 1;
        board.clear_board();
        board.setfood();
        cubies addpart;
        if (parts[size].xdir == -1) {
            addpart.xpos = parts[size].xpos + 1;
            addpart.ypos = parts[size].ypos;
        }
        if (parts[size].xdir == 1) {
            addpart.xpos = parts[size].xpos - 1;
            addpart.ypos = parts[size].ypos;
        }
        if (parts[size].ydir == -1) {
            addpart.ypos = parts[size].ypos + 1;
            addpart.xpos = parts[size].xpos;
        }
        if (parts[size].ydir == 1) {
            addpart.ypos = parts[size].ypos - 1;
            addpart.xpos = parts[size].xpos;
        }
        addpart.xdir = parts[size].xdir;
        addpart.ydir = parts[size].ydir;
        parts.push_back(addpart);
    }

    for (int cubie = 0; cubie < parts.size(); cubie++) {
        if (parts[cubie].xpos < 0) {
            parts[cubie].xpos = board.getwidth();
            continue;
        }
        if (parts[cubie].xpos > board.getwidth()) {
            parts[cubie].xpos = 0;
            continue;
        }
        if (parts[cubie].ypos > board.getheight()) {
            parts[cubie].xpos = 0;
            continue;
        }
        if (parts[cubie].xpos < 0) {
            parts[cubie].xpos = board.getheight();
            continue;
        }
    }
}

int Snake::gamestate() const {
    if (running == true) {
        return 0;
    } else {
        return 1;
    }
}
int Snake::gettiming() const {
    return miliseconds;
}

int Snake::getscore() const {
    return score;
}
