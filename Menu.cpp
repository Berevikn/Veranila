#include "Menu.h"

Menu::Menu(sf::Vector2f windowSize) {
    mButtonQuit->setSize(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 8.0f));
    mButtonResume->setSize(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 8.0f));
//    mButtonSettings->setSize(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 8.0f));
    mButtonStart->setSize(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 8.0f));
//    mSettingsMenu->setSize(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f));

    mButtonStart->setPosition(sf::Vector2f(windowSize.x / 4.0f, windowSize.y / 4.0f));
    mButtonResume->setPosition(sf::Vector2f(windowSize.x / 4.0f, windowSize.y / 8.0f * 3.0f));
//    mButtonSettings->setPosition(sf::Vector2f(windowSize.x / 4.0f, windowSize.y / 2.0f));
    mButtonQuit->setPosition(sf::Vector2f(windowSize.x / 4.0f, windowSize.y / 8.0f * 5.0f));
//    mSettingsMenu->setPosition(sf::Vector2f(windowSize.x / 4.0f, windowSize.y / 4.0f));

//    mSettingsMenu->setFillColor(sf::Color(219, 148, 9));

    mTextureQuit->loadFromFile("..\\quit.png");
    mTextureStart->loadFromFile("..\\start.png");
    mTextureResume->loadFromFile("..\\resume.png");
    mTextureSettings->loadFromFile("..\\settings.png");

    mButtonStart->setTexture(mTextureStart);
    mButtonQuit->setTexture(mTextureQuit);
    mButtonResume->setTexture(mTextureResume);
//    mButtonSettings->setTexture(mTextureSettings);

    mButtonStart->setOutlineColor(sf::Color::Black);
    mButtonResume->setOutlineColor(sf::Color::Black);
//    mButtonSettings->setOutlineColor(sf::Color::Black);
    mButtonQuit->setOutlineColor(sf::Color::Black);

    mButtonStart->setOutlineThickness(4.0f);
    mButtonResume->setOutlineThickness(4.0f);
//    mButtonSettings->setOutlineThickness(4.0f);
    mButtonQuit->setOutlineThickness(4.0f);

    *mIsStop = true;
    *mIsSettings = false;
}

bool Menu::isStop() {
    return *mIsStop;
}

void Menu::turnStop() {
    *mIsStop = !*mIsStop;
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (*mIsSettings) {
//        target.draw(*mSettingsMenu);
    } else {
        target.draw(*mButtonStart);
        target.draw(*mButtonResume);
//        target.draw(*mButtonSettings);
        target.draw(*mButtonQuit);
    }
}

Menu::~Menu() {
    delete mButtonStart;
    delete mButtonResume;
    delete mButtonQuit;
//    delete mButtonSettings;
    delete mTextureStart;
    delete mTextureQuit;
    delete mTextureSettings;
    delete mIsStop;
}

bool Menu::clickOnButtonStart(sf::Vector2i mousePosition) {
    return  ((float)mousePosition.x > mButtonStart->getPosition().x) &&
            ((float)mousePosition.x < mButtonStart->getPosition().x + mButtonStart->getSize().x) &&
            ((float)mousePosition.y > mButtonStart->getPosition().y) &&
            ((float)mousePosition.y < mButtonStart->getPosition().y + mButtonStart->getSize().y);
}

bool Menu::clickOnButtonResume(sf::Vector2i mousePosition) {
    return ((float)mousePosition.x > mButtonResume->getPosition().x) &&
           ((float)mousePosition.x < mButtonResume->getPosition().x + mButtonResume->getSize().x) &&
           ((float)mousePosition.y > mButtonResume->getPosition().y) &&
           ((float)mousePosition.y < mButtonResume->getPosition().y + mButtonResume->getSize().y);
}

//bool Menu::clickOnButtonSettings(sf::Vector2i mousePosition) {
//    return ((float)mousePosition.x > mButtonSettings->getPosition().x) &&
//           ((float)mousePosition.x < mButtonSettings->getPosition().x + mButtonSettings->getSize().x) &&
//           ((float)mousePosition.y > mButtonSettings->getPosition().y) &&
//           ((float)mousePosition.y < mButtonSettings->getPosition().y + mButtonSettings->getSize().y);
//}

bool Menu::clickOnButtonQuit(sf::Vector2i mousePosition) {
    return ((float)mousePosition.x > mButtonQuit->getPosition().x) &&
           ((float)mousePosition.x < mButtonQuit->getPosition().x + mButtonQuit->getSize().x) &&
           ((float)mousePosition.y > mButtonQuit->getPosition().y) &&
           ((float)mousePosition.y < mButtonQuit->getPosition().y + mButtonQuit->getSize().y);
}

//bool Menu::isSettings() {
//    return mIsSettings;
//}

//void Menu::turnSettings() {
//    *mIsSettings = !*mIsSettings;
//}
