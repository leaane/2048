#include "KeyEvents.h"

namespace KeyEvents {
    bool isPressed(sf::Event &event) {
        return event.type == sf::Event::KeyPressed;
    }

    bool isUpArrowPressed(sf::Event &event) {
        return isPressed(event) && event.key.code == sf::Keyboard::Up;
    }

    bool isDownArrowPressed(sf::Event &event) {
        return isPressed(event) && event.key.code == sf::Keyboard::Down;
    }

    bool isLeftArrowPressed(sf::Event &event) {
        return isPressed(event) && event.key.code == sf::Keyboard::Left;
    }

    bool isRightArrowPressed(sf::Event &event) {
        return isPressed(event) && event.key.code == sf::Keyboard::Right;
    }

    bool isWPressed(sf::Event &event) {
        return isPressed(event) && event.key.code == sf::Keyboard::W;
    }

    bool isAPressed(sf::Event &event) {
        return isPressed(event) && event.key.code == sf::Keyboard::A;
    }

    bool isSPressed(sf::Event &event) {
        return isPressed(event) && event.key.code == sf::Keyboard::S;
    }

    bool isDPressed(sf::Event &event) {
        return isPressed(event) && event.key.code == sf::Keyboard::D;
    }
}