#ifndef board_h
#define board_h

#include <string>

class Board {
    int height = 22, width = 22;
    int food_row, food_col;
    int field[50][50];
    std::string board;
public:
    Board(const std::string & board_play);
    int getheight() const;
    int getwidth() const;
    int getfoodrow() const;
    int getfoodcol() const;
    void setfood();
    int getboardstate(int width, int height) const;
    void display();
    void clear_board();
};

#endif //board_h
