#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "inc/log.hpp"
#include <ctime>
#include "inc/game.hpp"
#include "inc/Figures.hpp"
#include "inc/Board.hpp"


int main() {
    std::vector<std::vector<chess::Figures*>> figures(8, std::vector<chess::Figures*>(8));

    chess::Rook rookb1(false,0,0);
    figures[0][0] = &rookb1;
    chess::Horse horseb1(false,1,0);
    figures[0][1] = &horseb1;
    chess::Bishop bishopb1(false,2,0);
    figures[0][2] = &bishopb1;
    chess::Queen queenb(false,3,0);
    figures[0][3] = &queenb;
    chess::King kingb(false,4,0);
    figures[0][4] = &kingb;
    chess::Bishop bishopb2(false,5,0);
    figures[0][5] = &bishopb2;
    chess::Horse horseb2(false,6,0);
    figures[0][6] = &horseb2;
    chess::Rook rookb2(false,7,0);
    figures[0][7] = &rookb2;
    chess::Pawn pb1(false, 0, 1);
    figures[1][0] = &pb1;
    chess::Pawn pb2(false, 1, 1);
    figures[1][1] = &pb2;
    chess::Pawn pb3(false, 2, 1);
    figures[1][2] = &pb3;
    chess::Pawn pb4(false, 3, 1);
    figures[1][3] = &pb4;
    chess::Pawn pb5(false, 4, 1);
    figures[1][4] = &pb5;
    chess::Pawn pb6(false, 5, 1);
    figures[1][5] = &pb6;
    chess::Pawn pb7(false, 6, 1);
    figures[1][6] = &pb7;
    chess::Pawn pb8(false, 7, 1);
    figures[1][7] = &pb8;

    chess::Pawn pw1(true, 0, 6);
    figures[6][0] = &pw1;
    chess::Pawn pw2(true, 1, 6);
    figures[6][1] = &pw2;
    chess::Pawn pw3(true, 2, 6);
    figures[6][2] = &pw3;
    chess::Pawn pw4(true, 3, 6);
    figures[6][3] = &pw4;
    chess::Pawn pw5(true, 4, 6);
    figures[6][4] = &pw5;
    chess::Pawn pw6(true, 5, 6);
    figures[6][5] = &pw6;
    chess::Pawn pw7(true, 6, 6);
    figures[6][6] = &pw7;
    chess::Pawn pw8(true, 7, 6);
    figures[6][7] = &pw8;
    chess::Rook rookw1(true,0,7);
    figures[7][0] = &rookw1;
    chess::Horse horsew1(true,1,7);
    figures[7][1] = &horsew1;
    chess::Bishop bishopw1(true,2,7);
    figures[7][2] = &bishopw1;
    chess::Queen queenw(true,3,7);
    figures[7][3] = &queenw;
    chess::King kingw(true,4,7);
    figures[7][4] = &kingw;
    chess::Bishop bishopw2(true,5,7);
    figures[7][5] = &bishopw2;
    chess::Horse horsew2(true,6,7);
    figures[7][6] = &horsew2;
    chess::Rook rookw2(true,7,7);
    figures[7][7] = &rookw2;

    // 0 - пусто, 1 - Короли, 2 - Ферзи, 3 - Ладьи, 4 - Слоны, 5 - Кони, 6 - пешки
    short situation[8][8] = {{-3,-5,-4,-2,-1,-4,-5,-3},\
    {-6,-6,-6,-6,-6,-6,-6,-6},\
    {0,0,0,0,0,0,0,0},\
    {0,0,0,0,0,0,0,0},\
    {0,0,0,0,0,0,0,0},\
    {0,0,0,0,0,0,0,0},\
    {6,6,6,6,6,6,6,6},\
    {3,5,4,2,1,4,5,3}};
    chess::hodi(situation);
    Log::SetLogPath("log.txt");
    Log::Write(LogLevel::INFO, "Hi, world!");
    Log::Write(LogLevel::ERROR, "No  errors");
    Log::Write(LogLevel::INFO, "Congrats");

    sf::RenderWindow window(sf::VideoMode(2560, 1600), "The Chess");


    chess::Board deck;
    std::vector<chess::Possibility> possibility = figures[0][4]->can_move(situation);
    short flag = 1;
    bool choose;
    chess::Figures* cur_piece;
    sf::Vector2i localPosition;
    short px;
    short py;
    while (window.isOpen())
    {
        sf::Event event;

        window.clear();
        deck.draw(window);
        while (window.pollEvent(event))
        {
            switch (event.type) {
                // Window closed
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.key.code == sf::Mouse::Left){
                        localPosition = sf::Mouse::getPosition(window);
                        px = (localPosition.x - 200) / 100;
                        py = (localPosition.y - 100) / 100;
                        if(px >= 0 and px < 8 and py >= 0 and py < 8){
                            if (figures[py][px] != nullptr and flag % 2 == figures[py][px]->Get_color()){
                                possibility = figures[py][px]->can_move(situation);
                                cur_piece = figures[py][px];
                            }
                            else{
                                choose = false;
                                for (int i = 0; i < possibility.size(); i++){
                                    if (possibility[i].Get_x() == px and possibility[i].Get_y() == py){
                                        choose = true;
                                        break;
                                    }
                                }
                                if (choose){
                                    figures[py][px] = cur_piece;
                                    possibility = {};
                                    figures[cur_piece->Get_y()][cur_piece->Get_x()] = nullptr;
                                    situation[py][px] = cur_piece->Get_type();
                                    std::cout << cur_piece->Get_type() << std::endl;
                                    situation[cur_piece->Get_y()][cur_piece->Get_x()] = 0;
                                    cur_piece->Set_coord(px,py);

                                    flag++;
                                    chess::hodi(situation);
                                }
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }


        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if (figures[i][j] != nullptr)
                    window.draw(figures[i][j]->Get_piece());
            }
        }
        for (int i = 0; i < possibility.size(); i ++) {
            window.draw(possibility[i].Get_piece());
        }
        window.display();
    }
    Log::Write(LogLevel::DEBUG, "Program is ended");
    return 0;
}
