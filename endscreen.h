#ifndef endscreen_h
#define endscreen_h

#include <SFML/Graphics.hpp>
#include <string>

#include "reader.h"

class Endscreen {
    Reader & score;
    const int screen_height = 600;
    const int screen_width = 600;
    int outcome = 0;
public:
    explicit Endscreen (Reader & score, int result);
    void display();
    void drawOnWindow (sf::RenderWindow & win);
};

#endif //endscreen_h
