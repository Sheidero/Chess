#include <iostream>

namespace chess{
    bool hodi(short situate[8][8]);
    bool shakh(short situate[8][8], bool color);
    bool fight(short situate[8][8], short king_x, short king_y, short enemy_x, short enemy_y, short target, bool color);
}