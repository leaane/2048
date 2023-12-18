#include "Board.h"

Board::Board() : Board({500, 500}, sf::Color(191,178,158)) {}

Board::Board(sf::Vector2f size, sf::Color color) : rectangle(size) {
    rectangle.setFillColor(color);
}


void Board::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(rectangle);
}