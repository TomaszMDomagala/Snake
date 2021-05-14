#ifndef menu_h
#define menu_h
#include <SFML/Graphics.hpp>
#include <string>

class Menu {
    const int menu_screen_height = 600;
    const int menu_screen_width = 800;
    int game_screen_height = 0;
    int game_screen_width = 0;
    int option = 0;
public:
    void display();
    void drawOnWindow (sf::RenderWindow & win);
    int getscreenheight() {
        return game_screen_height;
    }
    int getscreenwidth() {
        return game_screen_width;
    }
    std::string getboardname();
    std::string getscorename();
};

#endif //menu_h
