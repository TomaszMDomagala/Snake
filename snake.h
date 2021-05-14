#ifndef snake_h
#define snake_h

#include <vector>
#include "board.h"

struct cubies {
    int xpos;
    int ypos;
    int xdir;
    int ydir;
};

class Snake {
    Board & board;
    std::vector<cubies> parts;
    bool running = true;
    unsigned int miliseconds = 200;
    unsigned int score = 0;
public:
    Snake(Board & board);
    bool isSnake(int x, int y);
    void display();
    void move();
    void turn(int side);
    void collision();
    int gamestate() const;
    int gettiming() const;
    int getscore() const;
};

#endif //snake_h
