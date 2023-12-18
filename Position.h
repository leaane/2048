#ifndef CS3A_POSITION_H
#define CS3A_POSITION_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Position {

public:
    template<typename T, typename S>
    static void left(const S& constObj, T& obj, float spacing = 0);
    template<typename T>
    static void centerText(const T &obj, sf::Text &text);
//right, top, center (of obj),bottom
};
//static dont need object just call like Position::left();
#include "Position.cpp" //need to include cpp at bottom so linker can find code (only if you use templates) see cpp
#endif //CS3A_POSITION_H

