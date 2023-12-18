#ifndef CS3A_BOARD_H
#define CS3A_BOARD_H

#include <SFML/Graphics.hpp>

class Board : public sf::Drawable {
private:
    sf::RectangleShape rectangle;

public:
    Board();
    Board(sf::Vector2f size, sf::Color color);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //CS3A_BOARD_H
