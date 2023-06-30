#include "../inc/game.hpp"
bool chess::hodi(short situate[8][8]){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++)
            std::cout << situate[i][j] << " ";
        std::cout << "\n";
    }
    return 0;
};

bool chess::shakh(short situate[8][8], bool color){
    // seeking king position
    short x,y;
    bool flag = false;
    for (int i = 0; i < 8; i++){
        for (int j = 0;j < 8; j++){
            if ((situate[i][j] == 1) and color){
                x = j;
                y = i;
                flag = true;
                break;
            }
            if ((situate[i][j] == -1) and not(color)){
                x = j;
                y = i;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    
}