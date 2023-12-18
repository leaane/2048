#include "Tile.h"

sf::Font Tile::font;
Tile::Tile() : Tile({100, 100}, sf::Color(202, 193, 181)) {}

Tile::Tile(sf::Vector2f size, sf::Color color) :  Tile(size, color, " ") {}

Tile::Tile(sf::Vector2f size, sf::Color color, const std::string &text) : rectangle(size) {
    setColor(color);

    if(!font.loadFromFile("OpenSans-Bold.ttf")) {
        exit(29);
    }

    setText(text);
}

void Tile::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(rectangle);
    window.draw(text);
}

void Tile::setTile(std::string text, sf::Color color) {
    setText(text);
    setColor(color);
}

void Tile::setPosition(sf::Vector2f position) {
    rectangle.setPosition(position);
}

void Tile::setColor(sf::Color color) {
    this->color = color;
    rectangle.setFillColor(color);
}

void Tile::setText(const std::string &text) {
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(30);
    setTextColor(sf::Color::White);
    Position::centerText(rectangle, this->text);
}

void Tile::setTextColor(sf::Color color) {
    this->text.setFillColor(color);
}

std::string Tile::getText() {
    return text.getString();
}

sf::Color Tile::getColor() {
    return color;
}