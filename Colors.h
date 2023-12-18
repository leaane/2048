#ifndef CS3A_COLORS_H
#define CS3A_COLORS_H

#include <SFML/Graphics.hpp>
#include "ColorsEnum.h"

class Colors {
public:
    static sf::Color getColor(ColorsEnum color);
    static sf::Color getColor(int num);
};


#endif //CS3A_COLORS_H
