#ifndef EVENTS_FIELD_H
#define EVENTS_FIELD_H

#include <SFML/Graphics.hpp>
#include "Square.h"

class Field: public sf::Drawable {
public:

    explicit Field(sf::Vector2f window);

    void init();

    sf::Vector2f getSizeSquare();

    void moveDown();
    void moveRight();
    void moveUp();
    void moveLeft();

    void isWin();

    bool isLose();

    ~Field() override;

private:

    void shiftDownInOnceLine(int j);
    void shiftRightInOnceLine(int i);
    void shiftUpInOnceLine(int j);
    void shiftLeftInOnceLine(int i);

    void addSquare();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::RectangleShape* mBackground = new sf::RectangleShape;
    sf::RectangleShape* mWIN = new sf::RectangleShape;
    sf::RectangleShape* mLOSE = new sf::RectangleShape;
    sf::Vector2f* mSize = new sf::Vector2f;
    sf::Vector2f* mSizeOfOnceSquare = new sf::Vector2f;
    sf::Clock* mSquareTime = new sf::Clock;
    sf::Texture* mBackgroundTexture = new sf::Texture;
    sf::Texture* mWinTexture = new sf::Texture;
    sf::Texture* mLoseTexture = new sf::Texture;
    int* mPositionX = new int;
    int* mPositionY = new int;
    int* mSquareOfSideCount = new int(4);
    int* mSquaresCountMoved = new int;
    Square** mSquares = new Square*[*mSquareOfSideCount];
    bool** mIsEmpty = new bool*[*mSquareOfSideCount];
    bool* mIsWin = new bool(false);
    bool* mIsLose = new bool(false);
};



#endif //EVENTS_FIELD_H
