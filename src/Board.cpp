#include "../inc/Board.hpp"
#include "SFML/Graphics.hpp"


chess::Board::Board() {
    float size = 100.f;
    bool isWhite = true;

    boardArray.setPrimitiveType(sf::Quads);
    boardArray.resize(64 * 4);

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int index = (i * 8 + j) * 4;
            sf::Vertex* quad = &boardArray[index];

            float left = j * size+200;
            float top = i * size+100;

            quad[0].position = sf::Vector2f(left, top);
            quad[1].position = sf::Vector2f(left + size, top);
            quad[2].position = sf::Vector2f(left + size, top + size);
            quad[3].position = sf::Vector2f(left, top + size);

            if (isWhite) {
                quad[0].color = sf::Color::White;
                quad[1].color = sf::Color::White;
                quad[2].color = sf::Color::White;
                quad[3].color = sf::Color::White;
            }
            else {
                quad[0].color = sf::Color(180,180,180);
                quad[1].color = sf::Color(180,180,180);
                quad[2].color = sf::Color(180,180,180);
                quad[3].color = sf::Color(180,180,180);
            }

            isWhite = !isWhite;
        }
        isWhite = !isWhite;
    }
}

void chess::Board::draw(sf::RenderWindow& window) {
    window.draw(boardArray);
}






