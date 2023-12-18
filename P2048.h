#ifndef CS3A_P2048_H
#define CS3A_P2048_H

#include "Board.h"
#include "Tile.h"
#include "Colors.h"
#include "KeyEvents.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>

class P2048 : public sf::Drawable {
private:
    Board board;
    Tile tiles[4][4];
    int score;
    bool lose;
    bool win;
    bool canMove;
    sf::RectangleShape rectangle;
    sf::Text text;
    static sf::Font font;

public:
    P2048();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void hideTiles();
    void addTile();
    bool mergeTiles(std::string direction);
    bool shiftTiles(std::string direction);
    void down();
    void up();
    void left();
    void right();
    void setText(const std::string &text);
    void fixTextColor();
    bool isBoardFull();
};

#endif //CS3A_P2048_H