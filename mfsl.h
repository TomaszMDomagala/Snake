#ifndef mfsl_h
#define mfsl_h

#include <SFML/Graphics.hpp>
#include "board.h"
#include "snake.h"
#include "menu.h"

class Mfsl {
    Board & board;
    Snake & snake;
    Menu & menu;
    int height;
    int width;
    int screen_width;
    int screen_height;
    sf::RectangleShape square;
public:
    Mfsl (Board & board, Snake & snake, Menu & menu);
    void drawOnWindow (sf::RenderWindow & win);
};

#endif //mfsl_h
