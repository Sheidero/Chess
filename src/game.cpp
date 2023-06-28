#include "../inc/game.hpp"
#include <iostream>

bool chess::can_move(short situate[8][8], short x, short y){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++)
            std::cout << situate[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
}