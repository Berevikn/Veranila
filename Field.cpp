#include "Field.h"
#include <iostream>
#include <stack>

Field::Field(sf::Vector2f window) {
    std::srand(std::time(0));
    *mSize = window;
    *mSizeOfOnceSquare = sf::Vector2f((*mSize).x / static_cast<float>(*mSquareOfSideCount), (*mSize).y / static_cast<float>(*mSquareOfSideCount));
    (*mBackgroundTexture).loadFromFile("..\\square0.png");
    (*mBackgroundTexture).setRepeated(true);
    (*mBackgroundTexture).setSmooth(true);
    (*mWinTexture).loadFromFile("..\\win.png");
    (*mWinTexture).setSmooth(true);
    (*mWinTexture).loadFromFile("..\\lose.png");
    (*mWinTexture).setSmooth(true);
    (*mBackground).setSize(*mSize);
    (*mWIN).setSize(*mSize);
    (*mWIN).setTexture(mWinTexture);
    (*mLOSE).setSize(*mSize);
    (*mLOSE).setTexture(mLoseTexture);
    (*mSquareTime).restart();
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        mSquares[i] = new Square[*mSquareOfSideCount];
        mIsEmpty[i] = new bool;
    }
}

void Field::init() {
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        for (int j = 0; j < *mSquareOfSideCount; ++j) {
            mIsEmpty[i][j] = true;
        }
    }
    (*mBackground).setTexture(mBackgroundTexture);
    (*mBackground).setTextureRect(sf::IntRect(0, 0, (*mSize).x, (*mSize).y));
    addSquare();
    addSquare();
}


void Field::addSquare() {
    do {
        (*mSquareTime).restart();
        *mPositionX = std::rand() % *mSquareOfSideCount;
        *mPositionY = std::rand() % *mSquareOfSideCount;
    } while(!mIsEmpty[*mPositionY][*mPositionX]);
    mSquares[*mPositionY][*mPositionX] = *(new Square(*mSizeOfOnceSquare));
    mSquares[*mPositionY][*mPositionX].updatePosition(sf::Vector2f(static_cast<float >(*mPositionX) * (*mSizeOfOnceSquare).x,
                                             static_cast<float>(*mPositionY) * (*mSizeOfOnceSquare).y));
    mIsEmpty[*mPositionY][*mPositionX] = false;
}

sf::Vector2f Field::getSizeSquare() {
    return *mSizeOfOnceSquare;
}

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*mBackground);
    for(int i = 0; i < *mSquareOfSideCount; ++i) {
        for(int j = 0; j < *mSquareOfSideCount; ++j) {
            if (!mIsEmpty[i][j]) {
                target.draw(mSquares[i][j]);
            }
        }
    }
    if(*mIsWin) {
        target.draw(*mWIN);
    }
    if(*mIsLose){
        target.draw(*mLOSE);
    }
}

void Field::moveDown() {
    for (int j = 0; j < *mSquareOfSideCount; ++j) {
        *mSquaresCountBefore = 0;
        for (int i = *mSquareOfSideCount - 1; i >= 0; --i) {
            if(!mIsEmpty[i][j]) {
                mIsEmpty[i][j] = true;
                if (*mSquaresCountBefore == 0 || mSquares[*mSquareOfSideCount - *mSquaresCountBefore][j].getLevel() != mSquares[i][j].getLevel()) {
                    mIsEmpty[*mSquareOfSideCount - 1 - *mSquaresCountBefore][j] = false;
                    mSquares[*mSquareOfSideCount - 1 - *mSquaresCountBefore][j] = mSquares[i][j];
                    mSquares[*mSquareOfSideCount - 1 - *mSquaresCountBefore][j].updatePosition(
                            sf::Vector2f(mSquares[*mSquareOfSideCount - 1 - *mSquaresCountBefore][j].getPosition().x,
                                         (float) (*mSquareOfSideCount - 1 - *mSquaresCountBefore) *
                                         (*mSizeOfOnceSquare).y));
                    ++(*mSquaresCountBefore);
                }
                else {
                    mSquares[*mSquareOfSideCount - *mSquaresCountBefore][j].levelUp();
                }
            }
        }
    }
    addSquare();
}

void Field::moveUp() {
    for (int j = 0; j < *mSquareOfSideCount; ++j) {
        *mSquaresCountBefore = 0;
        for (int i = 0; i < *mSquareOfSideCount; ++i) {
            if(!mIsEmpty[i][j]) {
                mIsEmpty[i][j] = true;
                if (*mSquaresCountBefore == 0 || mSquares[*mSquaresCountBefore - 1][j].getLevel() != mSquares[i][j].getLevel()) {
                    mIsEmpty[*mSquaresCountBefore][j] = false;
                    mSquares[*mSquaresCountBefore][j] = mSquares[i][j];
                    mSquares[*mSquaresCountBefore][j].updatePosition(
                            sf::Vector2f(mSquares[*mSquaresCountBefore][j].getPosition().x,
                                         (float) (*mSquaresCountBefore) * (*mSizeOfOnceSquare).y));
                    ++(*mSquaresCountBefore);
                }
                else {
                    mSquares[*mSquaresCountBefore - 1][j].levelUp();
                }
            }
        }
    }
    addSquare();
}

void Field::moveLeft() {
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        *mSquaresCountBefore = 0;
        for (int j = 0; j < *mSquareOfSideCount; ++j) {
            if(!mIsEmpty[i][j]) {
                mIsEmpty[i][j] = true;
                if (*mSquaresCountBefore == 0 || mSquares[i][*mSquaresCountBefore - 1].getLevel() != mSquares[i][j].getLevel()) {
                    mIsEmpty[i][*mSquaresCountBefore] = false;
                    mSquares[i][*mSquaresCountBefore] = mSquares[i][j];
                    mSquares[i][*mSquaresCountBefore].updatePosition(
                            sf::Vector2f((float) (*mSquaresCountBefore) * (*mSizeOfOnceSquare).x,
                                         mSquares[i][*mSquaresCountBefore].getPosition().y));
                    ++(*mSquaresCountBefore);
                }
                else {
                    mSquares[i][*mSquaresCountBefore - 1].levelUp();
                }
            }
        }
    }
    addSquare();
}


void Field::moveRight() {
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        *mSquaresCountBefore = 0;
        for (int j = *mSquareOfSideCount - 1; j >= 0; --j) {
            if(!mIsEmpty[i][j]) {
                mIsEmpty[i][j] = true;
                if (*mSquaresCountBefore == 0 || mSquares[i][*mSquareOfSideCount - *mSquaresCountBefore].getLevel() != mSquares[i][j].getLevel()) {
                    mIsEmpty[i][*mSquareOfSideCount - 1 - *mSquaresCountBefore] = false;
                    mSquares[i][*mSquareOfSideCount - 1 - *mSquaresCountBefore] = mSquares[i][j];
                    mSquares[i][*mSquareOfSideCount - 1 - *mSquaresCountBefore].updatePosition(
                            sf::Vector2f((float) (*mSquareOfSideCount - 1 - *mSquaresCountBefore) * (*mSizeOfOnceSquare).x,
                                         mSquares[i][*mSquareOfSideCount - 1 - *mSquaresCountBefore].getPosition().y));
                    ++(*mSquaresCountBefore);
                }
                else {
                    mSquares[i][*mSquareOfSideCount - *mSquaresCountBefore].levelUp();
                }
            }
        }
    }
    addSquare();
}

Field::~Field() {
    for(int i = 0; i < *mSquareOfSideCount; ++i) {
        delete mSquares[i];
        delete mIsEmpty[i];
    }
    delete[] mSquares;
    delete[] mIsEmpty;
    delete mSquaresCountBefore;
    delete mSizeOfOnceSquare;
    delete mSize;
    delete mPositionX;
    delete mBackground;
    delete mBackgroundTexture;
    delete mSquareTime;
    delete mPositionY;
    delete mSquareOfSideCount;
    delete mIsWin;
    delete mWinTexture;
    delete mWIN;
    delete mIsLose;
    delete mLoseTexture;
    delete mLOSE;
}

void Field::isWin() {
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        for (int j = 0; j < *mSquareOfSideCount; ++j) {
            if (!mIsEmpty[i][j] and mSquares[i][j].getLevel() == 11) {
                *mIsWin = true;
            }
        }
    }
}

bool Field::isLose() {
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        for (int j = 0; j < *mSquareOfSideCount; ++j) {
            if(mIsEmpty[i][j]) {
                return false;
            }
        }
    }
    std::stack<int>* previous = new std::stack<int>;
    int** status = new int*[*mSquareOfSideCount];
    for (int i = 0; i < *mSquareOfSideCount; ++i) {
        status[i] = new int[*mSquareOfSideCount];
        for (int j = 0; j < *mSquareOfSideCount; ++j) {
            status[i][j] = 0;
        }
    }
    int i = 0, j = 0;
    std::cout << "try: ";
    while (!(*previous).empty() || status[0][0] != 2) {
        std::cout << "I here: ";
        switch (status[i][j]) {
            case 0:
                std::cout << "0, ";
                ++status[i][j];
                if (i != *mSquareOfSideCount - 1) {
                    if (mSquares[i][j].getLevel() == mSquares[i + 1][j].getLevel()) {
                        return false;
                    }
                    if (status[i + 1][j] != 2) {
                        previous->push(1);
                        ++i;
                    }
                }
                break;
            case 1:
                std::cout << "1, ";
                ++status[i][j];
                if (j != *mSquareOfSideCount - 1) {
                    if (mSquares[i][j].getLevel() == mSquares[i][j + 1].getLevel()) {
                        return false;
                    }
                    if (status[i][j + 1] != 2) {
                        previous->push(2);
                        ++j;
                    }
                }
                break;
            case 2:
                std::cout << "2, ";
                if (previous->top() == 1) {
                    --i;
                } else {
                    --j;
                }
                previous->pop();
                break;
            default:
                std::cout << "INFINITY";
                break;
        }
        std::cout << std::endl;
    }
    delete previous;
    for (int k = 0; k < *mSquareOfSideCount; ++k) {
        delete status[k];
    }
    delete[] status;
    return true;
}


