#include <iostream>
#include <string>

#include "mfsl.h"

Mfsl::Mfsl(Board & board, Snake & snake, Menu & menu) : board(board), snake(snake), menu(menu)  {
    height = board.getheight();
    width = board.getwidth();
    screen_width = menu.getscreenwidth();
    screen_height = menu.getscreenheight();
    square.setSize(sf::Vector2f(screen_width/width, screen_height/height));

}

void Mfsl::drawOnWindow(sf::RenderWindow & win) {

    sf::Font font;
    if (!font.loadFromFile("./VeraSe.ttf")) {
        std::cout << "Error";
    }

    sf::Text lost_msg;
    if (snake.gamestate() == 1) {
        lost_msg.setFont(font);
        lost_msg.setFillColor(sf::Color::Red);
        lost_msg.setStyle(sf::Text::Bold);
        lost_msg.setOutlineColor(sf::Color::White);
        lost_msg.setOutlineThickness(2);
        lost_msg.setCharacterSize(30);
        lost_msg.setPosition(screen_width/2 - 80, screen_height/2);
        lost_msg.setString("You lost!");
    }

    for (int h = 0; h < height; h++) {
        int hpos = ((screen_height/height)*h);
        for (int w = 0; w < width; w++) {
            int wpos = ((screen_width/width)*w);
            if (board.getboardstate(w, h) == 9) {
                square.setFillColor(sf::Color(150, 150, 150));
            } else if (snake.isSnake(w, h) == true) {
                square.setFillColor(sf::Color::White);
            } else if (board.getboardstate(w, h) == 1) {
                square.setFillColor(sf::Color::Red);
            } else if (board.getboardstate(w, h) == 0) {
                square.setFillColor(sf::Color::Black);
            }

            square.setPosition(wpos, hpos);
            win.draw(square);
        }
    }
    win.draw(lost_msg);
}
