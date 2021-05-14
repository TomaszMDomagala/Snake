#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <unistd.h> // For sleep function

#include "menu.h"
#include "board.h"
#include "reader.h"
#include "mfsl.h"
#include "snake.h"
#include "endscreen.h"

int main() {

	Menu menu;
	menu.display();

	srand(time(NULL));

	sf::RenderWindow win(sf::VideoMode(menu.getscreenwidth(), menu.getscreenheight()), "Snake");
	win.setVerticalSyncEnabled(true);

	Reader read ('b', menu.getboardname());
	Board board (read.getboard());
	Snake snake (board);
	Mfsl view (board, snake, menu);

	while(win.isOpen()) {
		sf::Event event;

		win.clear(sf::Color(0, 0, 0));
		view.drawOnWindow(win);
		win.display();

		snake.display();

		while(win.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				win.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			snake.turn(4);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			snake.turn(3);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			snake.turn(2);
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			snake.turn(1);
		}

		snake.move();
		snake.collision();
		int miliseconds = snake.gettiming();
		usleep(miliseconds * 1000);
		std::system("clear");

		if (snake.gamestate() == 1) {
			view.drawOnWindow(win);
			win.display();
			sleep(2);
			win.close();
		}
	}

	Reader results ('w', menu.getscorename(), snake.getscore());
	Reader scores ('s', menu.getscorename());
	scores.sort_scores();

	Endscreen list (scores, snake.getscore());
	list.display();

	return 0;
}
