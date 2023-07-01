#include "../inc/game.hpp"
#include "../inc/Figures.hpp"
#include <vector>
#include <array>

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
    short king_x, king_y;
    short x, y;
    bool flag = false;
    for (int i = 0; i < 8; i++){
        for (int j = 0;j < 8; j++){
            if ((situate[i][j] == 1) and color){
                king_x = j;
                king_y = i;
                flag = true;
                break;
            }
            if ((situate[i][j] == -1) and not(color)){
                king_x = j;
                king_y = i;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    char check = chess::Figures::place(situate[y][x],color);
    x = king_x+1;
    y = king_y;
    while (x < 8 and check != 'a'){
        if (check == 'c'){
            if ( fight(situate,king_x,king_y,x,y,2,color)){
                return false;
            }
            break;
        }
        x++;
        check = chess::Figures::place(situate[y][x],color);
    }
    x = king_x - 1;
    y = king_y;
    check = chess::Figures::place(situate[y][x],color);
    while (x >= 0 and check != 'a'){
        if(check == 'c'){
            if ( fight(situate,king_x,king_y,x,y,6,color)){
                return false;
            }
            break;
        }
        x--;
        check = chess::Figures::place(situate[y][x],color);
    }
    x = king_x;
    y = king_y + 1;
    check = chess::Figures::place(situate[y][x],color);
    while (y < 8 and check != 'a'){
        if(check == 'c'){
            if ( fight(situate,king_x,king_y,x,y,4,color)){
                return false;
            }
            break;
        }
        y++;
        check = chess::Figures::place(situate[y][x],color);
    }
    x = king_x;
    y = king_y - 1;
    check = chess::Figures::place(situate[y][x],color);
    while (y >= 0 and check != 'a'){
        if(check == 'c'){
            if ( fight(situate,king_x,king_y,x,y,0,color)){
                return false;
            }
            break;
        }
        y--;
        check = chess::Figures::place(situate[y][x],color);
    }
    x = king_x -1;
    y = king_y -1;
    check = chess::Figures::place(situate[y][x],color);
    while (x>=0 and y >=0 and check != 'a'){
        if (check == 'c'){
            if ( fight(situate,king_x,king_y,x,y,7,color)){
                return false;
            }
            break;
        }
        x--;
        y--;
        check = chess::Figures::place(situate[y][x],color);
    }
    x = king_x -1;
    y = king_y + 1;
    check = chess::Figures::place(situate[y][x],color);
    while (x>=0 and y <8 and check != 'a'){
        if (check == 'c'){
            if ( fight(situate,king_x,king_y,x,y,5,color)){
                return false;
            }
            break;
        }
        x--;
        y++;
        check = chess::Figures::place(situate[y][x],color);
    }
    x = king_x + 1;
    y = king_y - 1;
    check = chess::Figures::place(situate[y][x],color);
    while (x<8 and y >=0 and check != 'a'){
        if (check == 'c'){
            if ( fight(situate,king_x,king_y,x,y,1,color)){
                return false;
            }
            break;
        }
        x++;
        y--;
        check = chess::Figures::place(situate[y][x],color);
    }
    x = king_x + 1;
    y = king_y + 1;
    check = chess::Figures::place(situate[y][x],color);
    while (x<8 and y <8 and check != 'a'){
        if (check == 'c'){
            if ( fight(situate,king_x,king_y,x,y,3,color)){
                return false;
            }
            break;
        }
        x++;
        y++;
        check = chess::Figures::place(situate[y][x],color);
    }
    x = king_x + 2;
    y = king_y;
    if (x < 8){
        y = king_y + 1;
        if (y < 8 and chess::Figures::place(situate[y][x],color) != 'a') {
            if (abs(situate[y][x]) == 5){
                return false;
            }
        }
        y = king_y - 1;
        if (y >= 0  and chess::Figures::place(situate[y][x],color) != 'a') {
            if (abs(situate[y][x]) == 5){
                return false;
            }
        }
    }
    x = king_x - 2;
    if (x >= 0) {
        y = king_y + 1;
        if (y < 8 and chess::Figures::place(situate[y][x],color) != 'a') {
            if (abs(situate[y][x]) == 5){
                return false;
            }
        }
        y = king_y - 1;
        if (y >= 0 and chess::Figures::place(situate[y][x],color) != 'a') {
            if (abs(situate[y][x]) == 5){
                return false;
            }
        }
    }
    y = king_y + 2;
    if (y < 8) {
        x = king_x + 1;
        if (x < 8 and chess::Figures::place(situate[y][x],color) != 'a') {
            if (abs(situate[y][x]) == 5){
                return false;
            }
        }
        x = king_x - 1;
        if (x >= 0 and chess::Figures::place(situate[y][x],color) != 'a') {
            if (abs(situate[y][x]) == 5){
                return false;
            }
        }
    }
    y = king_y - 2;
    if (y < 8) {
        x = king_x + 1;
        if (x < 8 and chess::Figures::place(situate[y][x],color) != 'a') {
            if (abs(situate[y][x]) == 5){
                return false;
            }
        }
        x = king_x - 1;
        if (x >= 0 and chess::Figures::place(situate[y][x],color) != 'a') {
            if (abs(situate[y][x]) == 5){
                return false;
            }
        }
    }
    return true;

}
bool chess::fight(short situation[8][8], short king_x, short king_y, short enemy_x, short enemy_y,short target, bool color){
    short type = abs(situation[enemy_y][enemy_x]);
    short x = enemy_x;
    short y = enemy_y;
    std::vector<std::array<short, 2>> vector;
    char check;
    switch (type) {
        case 1:
            check = chess::Figures::place(situation[y][x+1],color);
            if (x + 1 < 8 and check != 'a'){
                vector.push_back({static_cast<short>(x+1),y});
            }
            check = chess::Figures::place(situation[y+1][x+1],color);
            if (x + 1 < 8 and y +1 < 8 and check != 'a'){
                vector.push_back({static_cast<short>(x+1),static_cast<short>(y+1)});
            }
            check = chess::Figures::place(situation[y+1][x],color);
            if (y + 1 < 8 and check != 'a'){
                vector.push_back({x,static_cast<short>(y+1)});
            }
            check = chess::Figures::place(situation[y+1][x-1],color);
            if (x - 1 >= 0 and y+1 < 8 and check != 'a'){
                vector.push_back({static_cast<short>(x-1),static_cast<short>(y +1)});
            }
            check = chess::Figures::place(situation[y][x-1],color);
            if (x - 1 >= 0 and check != 'a'){
                vector.push_back({static_cast<short>(x-1),y});
            }
            check = chess::Figures::place(situation[y-1][x-1],color);
            if (x - 1 >=0 and y -1 >= 0 and check != 'a'){
                vector.push_back({static_cast<short>(x-1),static_cast<short>(y-1)});
            }
            check = chess::Figures::place(situation[y-1][x],color);
            if (y - 1 >= 0 and check != 'a'){
                vector.push_back({x,static_cast<short>(y-1)});
            }
            check = chess::Figures::place(situation[y-1][x+1],color);
            if (y-1 >= 0 and x + 1 < 8 and check != 'a'){
                vector.push_back({static_cast<short>(x+1),static_cast<short>(y-1)});
            }
            break;
        case 2:
            switch (target){
                case 0:
                    y = enemy_y - 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (y >= 0 and check != 'a'){
                        vector.push_back({x,y});
                        if(check == 'c'){
                            break;
                        }
                        y--;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 1:
                    x = enemy_x + 1;
                    y = enemy_y - 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (x<8 and y >=0 and check != 'a'){
                        vector.push_back({x,y});
                        if (check == 'c'){
                            break;
                        }
                        x++;
                        y--;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 2:
                    x = enemy_x + 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (x < 8 and check != 'a'){
                        vector.push_back({x,y});
                        if(check == 'c'){
                            break;
                        }
                        x++;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 3:
                    x = enemy_x + 1;
                    y = enemy_y + 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (x<8 and y <8 and check != 'a'){
                        vector.push_back({x,y});
                        if (check == 'c'){
                            break;
                        }
                        x++;
                        y++;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 4:
                    y = enemy_y + 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (y < 8 and check != 'a'){
                        vector.push_back({x,y});
                        if(check == 'c'){
                            break;
                        }
                        y++;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 5:
                    x = enemy_x -1;
                    y = enemy_y + 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (x>=0 and y <8 and check != 'a'){
                        vector.push_back({x,y});
                        if (check == 'c'){
                            break;
                        }
                        x--;
                        y++;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 6:
                    x = enemy_x - 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (x >= 0 and check != 'a'){
                        vector.push_back({x,y});
                        if(check == 'c'){
                            break;
                        }
                        x--;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 7:
                    x = enemy_x -1;
                    y = enemy_y -1;
                    char check = chess::Figures::place(situation[y][x],color);
                    while (x>=0 and y >=0 and check != 'a'){
                        vector.push_back({x,y});
                        if (check == 'c'){
                            break;
                        }
                        x--;
                        y--;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
            }
            break;
        case 3:
            switch (target) {
                case 0:
                    y = enemy_y - 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (y >= 0 and check != 'a'){
                        vector.push_back({x,y});
                        if(check == 'c'){
                            break;
                        }
                        y--;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 2:
                    x = enemy_x + 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (x < 8 and check != 'a'){
                        vector.push_back({x,y});
                        if(check == 'c'){
                            break;
                        }
                        x++;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 4:
                    y = enemy_y + 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (y < 8 and check != 'a'){
                        vector.push_back({x,y});
                        if(check == 'c'){
                            break;
                        }
                        y++;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 6:
                    x = enemy_x - 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (x >= 0 and check != 'a'){
                        vector.push_back({x,y});
                        if(check == 'c'){
                            break;
                        }
                        x--;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                default:
                    break;
            }
            break;
        case 4:
            switch (target) {
                case 1:
                    x = enemy_x + 1;
                    y = enemy_y - 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (x<8 and y >=0 and check != 'a'){
                        vector.push_back({x,y});
                        if (check == 'c'){
                            break;
                        }
                        x++;
                        y--;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 3:
                    x = enemy_x + 1;
                    y = enemy_y + 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (x<8 and y <8 and check != 'a'){
                        vector.push_back({x,y});
                        if (check == 'c'){
                            break;
                        }
                        x++;
                        y++;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 5:
                    x = enemy_x -1;
                    y = enemy_y + 1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (x>=0 and y <8 and check != 'a'){
                        vector.push_back({x,y});
                        if (check == 'c'){
                            break;
                        }
                        x--;
                        y++;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                case 7:
                    x = enemy_x -1;
                    y = enemy_y -1;
                    check = chess::Figures::place(situation[y][x],color);
                    while (x>=0 and y >=0 and check != 'a'){
                        vector.push_back({x,y});
                        if (check == 'c'){
                            break;
                        }
                        x--;
                        y--;
                        check = chess::Figures::place(situation[y][x],color);
                    }
                    break;
                default:
                    break;
            }
            break;
        case 6:
            if (color)
            {
                check = chess::Figures::place(situation[y - 1][x - 1], color);
                if (y - 1 >= 0 and x - 1 >= 0 and check == 'c')
                {
                    vector.push_back({static_cast<short>(x - 1), static_cast<short>(y - 1)});
                }
                check = chess::Figures::place(situation[y - 1][x + 1], color);
                if (y - 1 >= 0 and x + 1 <8 and check == 'c')
                {
                    vector.push_back({static_cast<short>(x + 1), static_cast<short>(y - 1)});
                }
            }
            if (!color)
            {
                check = chess::Figures::place(situation[y + 1][x - 1], color);
                if (y + 1 <= 7 and x - 1 >= 0 and check == 'c')
                {
                    vector.push_back({static_cast<short>(x - 1), static_cast<short>(y + 1)});
                }
                check = chess::Figures::place(situation[y + 1][x + 1], color);
                if (y + 1 <= 7 and x + 1 < 8 and check == 'c')
                {
                    vector.push_back({static_cast<short>(x + 1), static_cast<short>(y + 1)});
                }
            }
            break;

        default:
            break;
    }
    for (int i = 0; i < vector.size(); i++){
        if (vector[i][0] == king_x and vector[i][1] == king_y){
            return true;
        }
    }
    return false;
}