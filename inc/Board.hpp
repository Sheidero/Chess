#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace chess {
	class Board
	{
    private:
        sf::VertexArray boardArray;
        float squareSize;
    public:
        Board();
        void draw(sf::RenderWindow& window);

    
	};
}
