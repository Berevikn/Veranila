#include "Square.h"

Square::Square(sf::Vector2f size) {
    *mSize = size;
    (*mTexture).loadFromFile("..\\square1.png");
    (*mTexture).setSmooth(true);
    (*mSquare).setSize(*mSize);
    (*mSquare).setTexture(mTexture);
    (*mSquare).setTextureRect(sf::IntRect(0, 0, (*mSize).x, (*mSize).y));
    *mLevel = 1;
}

void Square::updatePosition(sf::Vector2f position) {
    (*mSquare).setPosition(position);
}

void Square::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*mSquare);
}

void Square::levelUp() {
    ++(*mLevel);
    switch(*mLevel) {
        case 2:
            (*mTexture).loadFromFile("..\\square2.png");
            break;
        case 3:
            (*mTexture).loadFromFile("..\\square3.png");
            break;
        case 4:
            (*mTexture).loadFromFile("..\\square4.png");
            break;
        case 5:
            (*mTexture).loadFromFile("..\\square5.png");
            break;
        case 6:
            (*mTexture).loadFromFile("..\\square6.png");
            break;
        case 7:
            (*mTexture).loadFromFile("..\\square7.png");
            break;
        case 8:
            (*mTexture).loadFromFile("..\\square8.png");
            break;
        case 9:
            (*mTexture).loadFromFile("..\\square9.png");
            break;
        case 10:
            (*mTexture).loadFromFile("..\\square10.png");
            break;
        case 11:
            (*mTexture).loadFromFile("..\\square11.png");
            break;
        default:
            (*mTexture).loadFromFile("..\\square1.png");
            break;
    }
}

sf::Vector2f Square::getPosition() {
    return mSquare->getPosition();
}

int Square::getLevel() {
    return *mLevel;
}

Square::~Square() {
    delete mSize;
    delete mSquare;
    delete mLevel;
    delete mTexture;
}
