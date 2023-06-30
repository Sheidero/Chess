#include "../inc/game.hpp"
bool chess::hodi(short situate[8][8]){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++)
            std::cout << situate[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
};