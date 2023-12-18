#ifndef CS3A_KEYEVENTS_H
#define CS3A_KEYEVENTS_H

#include <SFML/Graphics.hpp>

namespace KeyEvents {
    bool isPressed(sf::Event& event);
    bool isUpArrowPressed(sf::Event &event);
    bool isDownArrowPressed(sf::Event &event);
    bool isLeftArrowPressed(sf::Event &event);
    bool isRightArrowPressed(sf::Event &event);
    bool isWPressed(sf::Event &event);
    bool isAPressed(sf::Event &event);
    bool isSPressed(sf::Event &event);
    bool isDPressed(sf::Event &event);
};

#endif //CS3A_KEYEVENTS_H