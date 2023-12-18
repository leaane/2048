#ifndef CS3A_POSITION_CPP
#define CS3A_POSITION_CPP
#include "Position.h"

template<typename T, typename S>
void Position::left(const S& constObj, T& obj, float spacing) {
    sf::FloatRect constBounds = constObj.getGlobalBounds();
    sf::FloatRect objBounds = obj.getGlobalBounds();
    float x = constBounds.left - spacing - objBounds.width;
    float y = constBounds.top;
    obj.setPosition({x, y});
}

template<typename T>
void Position::centerText(const T &obj, sf::Text &text) {
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});
}



#endif