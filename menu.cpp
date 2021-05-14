#include "menu.h"
#include <iostream>

void Menu::display() {
    sf::RenderWindow win(sf::VideoMode(menu_screen_width, menu_screen_height), "Snake");
    win.setVerticalSyncEnabled(true);

    while(win.isOpen()) {
        sf::Event event;

        win.clear(sf::Color(0, 0, 0));
        drawOnWindow(win);
        win.display();

        int xmouse = 0, ymouse = 0;

        while(win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
    			if (event.mouseButton.button == sf::Mouse::Left) {
    				xmouse = event.mouseButton.x;
                    ymouse = event.mouseButton.y;
        		}
                if (xmouse > 15 && xmouse < 15 + (menu_screen_width/3)) {
                    if (ymouse > menu_screen_height/8 + 10 && ymouse < 60 + (menu_screen_width/3)) {
                        option = 1;
                        game_screen_width = 600;
                        game_screen_height = 600;
                    }
                }
                if (xmouse > 15 + (menu_screen_width/3) && xmouse < 15 + ((menu_screen_width/3) * 2)) {
                    if (ymouse > menu_screen_height/8 + 10 && ymouse < 60 + (menu_screen_width/3)) {
                        option = 2;
                        game_screen_width = 600;
                        game_screen_height = 600;
                    }
                }
                if (xmouse > 15 + ((menu_screen_width/3)*2) && xmouse < 15 + ((menu_screen_width/3) * 3)) {
                    if (ymouse > menu_screen_height/8 + 10 && ymouse < 60 + (menu_screen_width/3)) {
                        option = 3;
                        game_screen_width = 600;
                        game_screen_height = 600;
                    }
                }

                if (xmouse > 15 && xmouse < 15 + (menu_screen_width/3)) {
                    if (ymouse > menu_screen_height/8 + 10 + menu_screen_width/3) {
                        option = 4;
                        game_screen_width = 400;
                        game_screen_height = 400;
                    }
                }
                if (xmouse > 15 + (menu_screen_width/3) && xmouse < 15 + ((menu_screen_width/3) * 2)) {
                    if (ymouse > menu_screen_height/8 + 10 + menu_screen_width/3) {
                        option = 5;
                        game_screen_width = 400;
                        game_screen_height = 400;
                    }
                }
                if (xmouse > 15 + ((menu_screen_width/3)*2) && xmouse < 15 + ((menu_screen_width/3) * 3)) {
                    if (ymouse > menu_screen_height/8 + 10 + menu_screen_width/3) {
                        option = 6;
                        game_screen_width = 400;
                        game_screen_height = 400;
                    }
                }
    		}
        }
        if (option != 0) {
            win.close();
        }
    }
}

void Menu::drawOnWindow(sf::RenderWindow & win) {

    sf::Font font;
    if (!font.loadFromFile("./VeraSe.ttf")) {
        std::cout << "Error";
    }

    sf::RectangleShape square;
    square.setSize(sf::Vector2f(menu_screen_width, menu_screen_height/8));
    square.setPosition(0, 0);
    square.setFillColor(sf::Color(100, 100, 100));
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(3);
    text.setCharacterSize(50);
    text.setPosition(menu_screen_width/2 - 70, 5);
    text.setString("Snake");

    sf::RectangleShape boards;
    sf::Text board_text;
    board_text.setFont(font);
    board_text.setFillColor(sf::Color::White);
    board_text.setStyle(sf::Text::Bold);
    board_text.setOutlineColor(sf::Color::Black);
    board_text.setOutlineThickness(2);
    board_text.setCharacterSize(40);
    sf::Text hard;
    hard.setFont(font);
    hard.setFillColor(sf::Color::White);
    hard.setStyle(sf::Text::Bold);
    hard.setOutlineColor(sf::Color::Red);
    hard.setOutlineThickness(2);
    hard.setCharacterSize(40);

    for (int col = 0; col < 2; col++) {
        for (int row = 0; row < 3; row++) {
            boards.setSize(sf::Vector2f(menu_screen_width/3 - 25, menu_screen_width/3 - 25));
            boards.setPosition(15 + (row * (menu_screen_width/3)), menu_screen_height/8 + 10 + (col * (menu_screen_width/3)));
            boards.setFillColor(sf::Color::White);
            board_text.setPosition(60 + (row * (menu_screen_width/3)), menu_screen_height/8 + 105 + (col * (menu_screen_width/3)));
            if (row == 0 && col == 0) {
                board_text.setString("Level 1");
            } else if(row == 1 && col == 0) {
                board_text.setString("Level 2");
            } else if (row == 2 && col == 0) {
                board_text.setString("Level 3");
            } else if (row == 0 && col == 1) {
                hard.setPosition(60 + (row * (menu_screen_width/3)), menu_screen_height/8 + 65 + (col * (menu_screen_width/3)));
                hard.setString("Hard");
                board_text.setString("Level 1");
            } else if(row == 1 && col == 1) {
                hard.setPosition(60 + (row * (menu_screen_width/3)), menu_screen_height/8 + 65 + (col * (menu_screen_width/3)));
                hard.setString("Hard");
                board_text.setString("Level 2");
            } else if (row == 2 && col == 1) {
                hard.setPosition(60 + (row * (menu_screen_width/3)), menu_screen_height/8 + 65 + (col * (menu_screen_width/3)));
                hard.setString("Hard");
                board_text.setString("Level 3");
            }
            win.draw(boards);
            win.draw(board_text);
            win.draw(hard);
        }
    }

    win.draw(square);
    win.draw(text);
}

std::string Menu::getboardname() {
    if (option == 1) {
        return "board1";
    } else if (option == 2) {
        return "board2";
    } else if (option == 3) {
        return "board3";
    } else if (option == 4) {
        return "board4";
    } else if (option == 5) {
        return "board5";
    } else if (option == 6) {
        return "board6";
    } else {
        return "Error";
    }
}

std::string Menu::getscorename() {
    if (option == 1) {
        return "scores1";
    } else if (option == 2) {
        return "scores2";
    } else if (option == 3) {
        return "scores3";
    } else if (option == 4) {
        return "scores4";
    } else if (option == 5) {
        return "scores5";
    } else if (option == 6) {
        return "scores6";
    } else {
        return "Error";
    }
}
