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
                if (myField.isLose()) {
                    std::cout << "LOH" << std::endl;
                    if (event.key.code == Keyboard::Enter) {
                        myField.init();
                    }
                } else {
                    if (event.key.code == Keyboard::Down) {
                            myField.moveDown();
                            std::cout << "DOWN" << std::endl;
                    }
                    if (event.key.code == Keyboard::Up) {
                            myField.moveUp();
                            std::cout << "UP" << std::endl;
                    }
                    if (event.key.code == Keyboard::Right) {
                            myField.moveRight();
                            std::cout << "RIGHT" << std::endl;
                    }
                    if (event.key.code == Keyboard::Left) {
                            myField.moveLeft();
                            std::cout << "LEFT" << std::endl;
                    }
                    myField.isWin();
                }
            }

        }
        window.clear();
        window.draw(myField);
        window.display();
    }

    return 0;
}