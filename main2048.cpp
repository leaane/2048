#include "P2048.h"
#include <ctime>

int main() {
    std::srand(std::time(0));
    sf::VideoMode videoMode(500, 500, 32);
    sf::RenderWindow window(videoMode,"2048");
    window.setFramerateLimit(60);

    P2048 game;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            game.eventHandler(window, event);
        }

        window.clear();
        window.draw(game);
        window.display();
    }

    return 0;
}