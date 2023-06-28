#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "inc/log.hpp"
#include <ctime>
#include "inc/game.hpp"
#include "inc/Figures.hpp"
#include "inc/Board.hpp"

#define N 10
int main() {
    // 0 - пусто, 1 - Короли, 2 - Ферзи, 3 - Ладьи, 4 - Слоны, 5 - Кони, 6 - пешки
    short situation[8][8] = {{-3,-5,-4,-2,-1,-4,-5,-3},\
    {-6,-6,-6,-6,-6,-6,-6,-6},\
    {0,0,0,0,0,0,0,0},\
    {0,0,0,0,0,0,0,0},\
    {0,0,0,0,0,0,0,0},\
    {0,0,0,0,0,0,0,0},\
    {6,6,6,6,6,6,6,6},\
    {3,5,4,2,1,4,5,3}};
    chess::can_move(situation,1,2);
    Log::SetLogPath("log.txt");
    Log::Write(LogLevel::INFO, "Hi, world!");
    Log::Write(LogLevel::ERROR, "No  errors");
    Log::Write(LogLevel::INFO, "Congrats");
    Log::Write(LogLevel::DEBUG, "Program is ended");

    sf::RenderWindow window(sf::VideoMode(2560, 1600), "The Chess");
    short x = 2;
    short y = 3;
    bool a = false;

    chess::Pawn k(a, x, y);
    chess::Possibility circle(x, y);
    chess::Board deck;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        deck.draw(window);
        window.draw(k.Get_piece());
        window.draw(circle.Get_piece());
        window.display();
    }

    return 0;
}
