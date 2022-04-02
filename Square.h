#ifndef EVENTS_SQUARE_H
#define EVENTS_SQUARE_H

#include <SFML/Graphics.hpp>

class Square: public sf::Drawable{
public:
    explicit Square(sf::Vector2f size = sf::Vector2f(0, 0));

    int getLevel();

    void levelUp();

    void updatePosition(sf::Vector2f position);

    sf::Vector2f getPosition();

    ~Square() override;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::RectangleShape* mSquare = new sf::RectangleShape;
    sf::Vector2f* mSize = new sf::Vector2f;
    sf::Texture* mTexture = new sf::Texture;
    int* mLevel = new int;
};

#endif //EVENTS_SQUARE_H
