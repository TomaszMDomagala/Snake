#include "endscreen.h"
#include <iostream>
#include <string>

Endscreen::Endscreen (Reader & score, int result) : score(score) {
    outcome = result;
}

void Endscreen::display() {
    sf::RenderWindow win(sf::VideoMode(screen_width, screen_height), "Snake");
    win.setVerticalSyncEnabled(true);

    while(win.isOpen()) {
        sf::Event event;

        win.clear(sf::Color(0, 0, 0));
        drawOnWindow(win);
        win.display();

        while(win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                win.close();
            }
        }
    }
}

void Endscreen::drawOnWindow(sf::RenderWindow & win) {

    sf::Font font;
    if (!font.loadFromFile("./VeraSe.ttf")) {
        std::cout << "Error";
    }
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(3);
    text.setCharacterSize(50);
    text.setPosition(screen_width/2 - 200, 10);
    text.setString("Your score: ");
    win.draw(text);

    sf::Text thisscore;
    thisscore.setFont(font);
    thisscore.setFillColor(sf::Color::White);
    thisscore.setStyle(sf::Text::Bold);
    thisscore.setOutlineColor(sf::Color::Black);
    thisscore.setOutlineThickness(3);
    thisscore.setCharacterSize(50);
    thisscore.setPosition(screen_width/2 + 150, 10);
    std::string s = std::to_string(outcome);
    thisscore.setString(s);
    win.draw(thisscore);


    sf::Text scores;
    sf::Text place;
    scores.setFont(font);
    scores.setFillColor(sf::Color::White);
    scores.setStyle(sf::Text::Bold);
    scores.setCharacterSize(20);
    place.setFont(font);
    place.setFillColor(sf::Color::White);
    place.setStyle(sf::Text::Bold);
    place.setCharacterSize(20);
    for (int i = 1; i < 11; i++) {
        int out = score.getscore(i);
        scores.setPosition(screen_width/2 - 10, 50 + (50 * i));
        place.setPosition(screen_width/2 - 70, 50 + (50 * i));
        std::string s = std::to_string(out);
        std::string p = std::to_string(i);
        scores.setString(s);
        place.setString(p + ". ");
        win.draw(scores);
        win.draw(place);
    }
}
