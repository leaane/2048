#ifndef CS3A_TILE_H
#define CS3A_TILE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Position.h"

class Tile : public sf::Drawable {
private:
    sf::RectangleShape rectangle;
    sf::Text text;
    static sf::Font font;
    sf::Color color;

public:
    Tile();
    Tile(sf::Vector2f size, sf::Color color);
    Tile(sf::Vector2f size, sf::Color color, const std::string &text);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void setTile(std::string text, sf::Color color);
    void setPosition(sf::Vector2f position);
    void setColor(sf::Color color);
    void setText(const std::string &text);
    void setTextColor(sf::Color color);
    std::string getText();
    sf::Color getColor();
};


#endif //CS3A_TILE_H
