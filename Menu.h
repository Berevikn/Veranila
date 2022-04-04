#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include <SFML/Graphics.hpp>

class Menu: public sf::Drawable{
public:
    Menu(sf::Vector2f windowSize);
    bool clickOnButtonStart(sf::Vector2i mousePosition);
    bool clickOnButtonResume(sf::Vector2i mousePosition);
//    bool clickOnButtonSettings(sf::Vector2i mousePosition);
    bool clickOnButtonQuit(sf::Vector2i mousePosition);
    bool isStop();
//    bool isSettings();
    void turnStop();
//    void turnSettings();
    ~Menu();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::RectangleShape* mButtonStart = new sf::RectangleShape;
    sf::RectangleShape* mButtonResume = new sf::RectangleShape;
    sf::RectangleShape* mButtonQuit = new sf::RectangleShape;
//    sf::RectangleShape* mButtonSettings = new sf::RectangleShape;
//    sf::RectangleShape* mSettingsMenu = new sf::RectangleShape;
    sf::Texture* mTextureStart = new sf::Texture;
    sf::Texture* mTextureResume = new sf::Texture;
    sf::Texture* mTextureQuit = new sf::Texture;
    sf::Texture* mTextureSettings = new sf::Texture;
    bool* mIsStop = new bool;
    bool* mIsSettings = new bool;
};

#endif //MAIN_CPP_MENU_H
