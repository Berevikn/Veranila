#include <SFML/Graphics.hpp>
#include <iostream>
#include "Field.h"
#include "Menu.h"

using namespace sf;

int main() {
    RenderWindow window(sf::VideoMode(800, 800), "2048");
    window.setFramerateLimit(60);
    Field myField(Vector2f(800, 800));
    Menu menu(Vector2f(800, 800));

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (menu.isStop()) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (menu.clickOnButtonStart(sf::Mouse::getPosition(window))) {
                        myField.init();
                        menu.turnStop();
                    }else if (menu.clickOnButtonResume(sf::Mouse::getPosition(window))) {
                        menu.turnStop();
                    }
//                    else if (menu.clickOnButtonSettings(sf::Mouse::getPosition(window))) {
//                        menu.turnSettings();
//                    }
                    else if (menu.clickOnButtonQuit(sf::Mouse::getPosition(window))) {
                        window.close();
                    }
                }
            }
            if (event.type == Event::KeyPressed){
                if (event.key.code == Keyboard::Escape) {
                    menu.turnStop();
                }
                if (!menu.isStop()) {
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

        }
        window.clear();
        window.draw(myField);
        if (menu.isStop()) {
            window.draw(menu);
        }
        window.display();
    }

    return 0;
}