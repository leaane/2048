#include "P2048.h"

sf::Font P2048::font;
P2048::P2048() {
    //Starting positions
    lose = false;
    win = false;
    canMove = true;
    score = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            float xPos = (20.0f * (j+1)) + (j * 100.0f);
            float yPos = (20.0f * (i+1)) + (i * 100.0f);

            tiles[i][j] = Tile();
            tiles[i][j].setPosition({xPos, yPos});
        }
    }
    tiles[1][2].setTile("2", Colors::getColor(C2));
    tiles[1][2].setTextColor(sf::Color::Black);
    tiles[3][3].setTile("2", Colors::getColor(C2));
    tiles[3][3].setTextColor(sf::Color::Black);

    rectangle.setSize(sf::Vector2f(500, 500));
    if(!font.loadFromFile("OpenSans-Bold.ttf")) {
        exit(28);
    }
}

void P2048::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(board);
    for (const auto & tile : tiles) {
        for (const auto & j : tile) {
            window.draw(j);
        }
    }
    window.draw(text);
}

void P2048::eventHandler(sf::RenderWindow &window, sf::Event event) {
    bool clicked = false;
    if ((!win) && (!lose)) {
        if (KeyEvents::isUpArrowPressed(event) || KeyEvents::isWPressed(event)) {
            up();
            if (canMove) {
                clicked = true;
                canMove = false;
            }
        } else if (KeyEvents::isLeftArrowPressed(event) || KeyEvents::isAPressed(event)) {
            left();
            if (canMove) {
                clicked = true;
                canMove = false;
            }
        } else if (KeyEvents::isDownArrowPressed(event) || KeyEvents::isSPressed(event)) {
            down();
            if (canMove) {
                clicked = true;
                canMove = false;
            }
        } else if (KeyEvents::isRightArrowPressed(event) || KeyEvents::isDPressed(event)) {
            right();
            if (canMove) {
                clicked = true;
                canMove = false;
            }
        }
    }

    fixTextColor();

    if ((!lose) && (clicked)) {
        addTile();
    } else if (lose) {
        setText("Game over!\nScore: " + std::to_string(score));
        hideTiles();
    }

    //Ends game when 2048 tile is reached, wins
    for (auto & tile : tiles) {
        for (auto & j : tile) {
            if (j.getText() == "2048") {
                setText("You won!");
                hideTiles();
                win = true;
            }
        }
    }

}

void P2048::addTile() {
    //Finds empty spaces to add a tile
    std::vector<std::pair<int, int>> spaces;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tiles[i][j].getText() == " ") {
                spaces.push_back(std::make_pair(i, j));
            }
        }
    }

    //Randomly picks an empty tile to replace with a 2
    if (!spaces.empty()) {
        int randomIndex = std::rand() % spaces.size();
        int i = spaces[randomIndex].first;
        int j = spaces[randomIndex].second;

        tiles[i][j].setTile("2", Colors::getColor(C2));
        tiles[i][j].setTextColor(sf::Color::Black);
    } else {
        //Game over if no spaces to add tile
        lose = true;
    }
}

bool P2048::mergeTiles(std::string direction) {
    bool canMerge = false;
    if (direction == "left") {
        for (int i = 0; i < 4; i++) {
            std::string numText = "";
            int prev = 0;
            for (int j = 0; j < 4; j++) {
                if ((!numText.empty()) && (numText == tiles[i][j].getText()) && (numText != " ")) {
                    int num = std::stoi(numText);
                    tiles[i][prev].setTile(std::to_string(num*2), Colors::getColor(num*2));
                    tiles[i][j].setTile(" ", Colors::getColor(BLANK));
                    score += 2*num;
                    numText = " ";
                    canMerge = true;
                    continue;
                }
                if (tiles[i][j].getText() != " "){
                    numText = tiles[i][j].getText();
                    prev = j;
                }
            }
        }
    } else if (direction == "right") {
        for (int i = 0; i < 4; i++) {
            std::string numText = "";
            int prev = 0;
            for (int j = 3; j >= 0; j--) {
                if ((!numText.empty()) && (numText == tiles[i][j].getText()) && (numText != " ")) {
                    int num = std::stoi(numText);
                    tiles[i][prev].setTile(std::to_string(num*2), Colors::getColor(num*2));
                    tiles[i][j].setTile(" ", Colors::getColor(BLANK));
                    score += 2*num;
                    numText = " ";
                    canMerge = true;
                    continue;
                }
                if (tiles[i][j].getText() != " "){
                    numText = tiles[i][j].getText();
                    prev = j;
                }
            }
        }
    } else if (direction == "up") {
        for(int i = 0; i < 4; i++) {
            std::string numText = "";
            int prev = 0;
            for (int j = 0; j < 4; j++) {
                if ((!numText.empty()) && (numText == tiles[j][i].getText()) && (numText != " ")) {
                    int num = std::stoi(numText);
                    tiles[prev][i].setTile(std::to_string(num*2), Colors::getColor(num*2));
                    tiles[j][i].setTile(" ", Colors::getColor(BLANK));
                    score += num*2;
                    numText = " ";
                    canMerge = true;
                    continue;
                }
                if (tiles[j][i].getText() != " ") {
                    numText = tiles[j][i].getText();
                    prev = j;
                }
            }
        }
    } else if (direction == "down") {
            for(int i = 0; i < 4; i++) {
                std::string numText = "";
                int prev = 0;
                for (int j = 3; j >= 0; j--) {
                    if ((!numText.empty()) && (numText == tiles[j][i].getText()) && (numText != " ")) {
                        int num = std::stoi(numText);
                        tiles[prev][i].setTile(std::to_string(num*2), Colors::getColor(num*2));
                        tiles[j][i].setTile(" ", Colors::getColor(BLANK));
                        score += num*2;
                        numText = " ";
                        canMerge = true;
                        continue;
                    }
                    if (tiles[j][i].getText() != " ") {
                        numText = tiles[j][i].getText();
                        prev = j;
                    }
                }
            }
        }
    return canMerge;
}

bool P2048::shiftTiles(std::string direction) {
    bool canShift = false;
    if (direction == "up") {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 3; k++) {
                    if (tiles[k][i].getText() == " " && tiles[k+1][i].getText() != " ") {
                        Tile temp = tiles[k][i];
                        tiles[k][i].setTile(tiles[k+1][i].getText(), tiles[k+1][i].getColor());
                        tiles[k+1][i].setTile(temp.getText(), temp.getColor());
                        canShift = true;
                    }
                }
            }
        }
    } else if (direction == "down") {
        for (int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++){
                for(int k = 3; k > 0; k--) {
                    if(tiles[k][i].getText() == " " && tiles[k-1][i].getText() != " ") {
                        Tile temp = tiles[k][i];
                        tiles[k][i].setTile(tiles[k-1][i].getText(), tiles[k-1][i].getColor());
                        tiles[k-1][i].setTile(temp.getText(), temp.getColor());
                        canShift = true;
                    }
                }
            }
        }
    } else if (direction == "left") {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for(int k = 0; k < 3; k++) {
                    if(tiles[i][k].getText() == " " && tiles[i][k+1].getText() != " ") {
                        Tile temp = tiles[i][k];
                        tiles[i][k].setTile(tiles[i][k+1].getText(), tiles[i][k+1].getColor());
                        tiles[i][k+1].setTile(temp.getText(), temp.getColor());
                        canShift = true;
                    }
                }
            }
        }
    } else if (direction == "right") {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 3; k > 0; k--) {
                    if(tiles[i][k].getText() == " " && tiles[i][k-1].getText()!= " ") {
                        Tile temp = tiles[i][k];
                        tiles[i][k].setTile(tiles[i][k-1].getText(), tiles[i][k-1].getColor());
                        tiles[i][k-1].setTile(temp.getText(), temp.getColor());
                        canShift = true;
                    }
                }
            }
        }
    }
    return canShift;
}

void P2048::down() {
    P2048 originalState = *this;
    bool merge = mergeTiles("down");
    bool shift = shiftTiles("down");
    if (merge || shift) {
        canMove = true;
    } else if (isBoardFull() && !mergeTiles("left") && !mergeTiles("up") && !mergeTiles("right")) {
        lose = true;
    } else {
        *this = originalState;
    }
}

void P2048::up() {
    P2048 originalState = *this;
    bool merge = mergeTiles("up");
    bool shift = shiftTiles("up");
    if (merge || shift) {
        canMove = true;
    } else if (isBoardFull() && !mergeTiles("left") && !mergeTiles("right") && !mergeTiles("down")) {
        lose = true;
    } else {
        *this = originalState;
    }
}

void P2048::left() {
    P2048 originalState = *this;
    bool merge = mergeTiles("left");
    bool shift = shiftTiles("left");
    if (merge|| shift) {
        canMove = true;
    } else if (isBoardFull() && !mergeTiles("right") && !mergeTiles("up") && !mergeTiles("down")) {
        lose = true;
    } else {
        *this = originalState; //Undoes merges if user can move but is pressing directions that can't merge
    }
}

void P2048::right() {
    P2048 originalState = *this;
    bool merge = mergeTiles("right");
    bool shift = shiftTiles("right");
    if (merge || shift) {
        canMove = true;
    } else if (isBoardFull() && !mergeTiles("left") && !mergeTiles("up") && !mergeTiles("down")) {
        lose = true;
    } else {
        *this = originalState;
    }
}

bool P2048::isBoardFull() {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tiles[i][j].getText() != " ") {
                count++;
            }
        }
    }
    return count == 16;
}

//Adjusts opacity of the tiles once user wins or loses
void P2048::hideTiles() {
    for (auto & tile : tiles) {
        for (auto & j : tile) {
            sf::Color color = j.getColor();
            color.a = 80;
            j.setColor(color);
        }
    }
}

void P2048::setText(const std::string &text) {
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(40);
    this->text.setFillColor(sf::Color::Black);
    Position::centerText(rectangle, this->text);
}

//Changes all 2's and 4's text to black
void P2048::fixTextColor() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tiles[i][j].getText() == "2" || tiles[i][j].getText() == "4") {
                tiles[i][j].setTextColor(sf::Color::Black);
            }
        }
    }
}