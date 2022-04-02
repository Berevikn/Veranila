#include <SFML/Graphics.hpp>
#include <iostream>
#include "Field.h"

using namespace sf;

int main() {
    RenderWindow window(sf::VideoMode(800, 800), "2048");
    window.setFramerateLimit(60);
    Field myField(Vector2f(800, 800));
    myField.init();

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::KeyPressed){
                if (event.key.code == Keyboard::Down) {
                    if (!myField.isLose()) {
                        myField.moveDown();
                        myField.isWin();
                    }
                }
                if (event.key.code == Keyboard::Up) {
                    if (!myField.isLose()) {
                        myField.moveUp();
                        myField.isWin();
                    }
                }
                if (event.key.code == Keyboard::Right) {
                    if (!myField.isLose()) {
                        myField.moveRight();
                        myField.isWin();
                    }
                }
                if (event.key.code == Keyboard::Left) {
                    if (!myField.isLose()) {
                        myField.moveLeft();
                        myField.isWin();
                    }
                }
                if (event.key.code == Keyboard::Enter) {
                    myField.init();
                }
            }

        }
        window.clear();
        window.draw(myField);
        window.display();
    }

    return 0;
}