#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../inc/log.hpp"
#include "../inc/game.hpp"
namespace chess{
    class Possibility{
    private:
        short m_size = 40;
        short m_x;
        short m_y;
        sf::CircleShape m_circle;
    public:
        Possibility(short x, short y){
            m_x = x;
            m_y = y;
            m_circle.setRadius(m_size);
            m_circle.setPosition(210 + m_x * 100,110 + m_y * 100);
            m_circle.setFillColor(sf::Color(200,0,0,50));
        }
        ~Possibility() {};
        sf::CircleShape Get_piece(){
            return m_circle;
        }
        void Set_coord(short x, short y){
            m_x = x;
            m_y = y;
            m_circle.setPosition(210 + m_x * 100,110 + m_y * 100);
        }
        short Get_x(){
            return m_x;
        }
        short Get_y(){
            return m_y;
        }
    };

    class Figures{
    protected:
        // 1 - Короли, 2 - Ферзи, 3 - Ладьи, 4 - Слоны, 5 - Кони, 6 - пешки, - чёрные, 0 - ничего
        short m_type;
        // 0 - чёрные, 1 - белые
        bool m_color;
        sf::Sprite m_visual;
        short m_x;
        short m_y;
        // 27
        std::vector<Possibility> m_possibility;
    public:
        Figures(){};
        Figures(bool& color, short& x, short& y){
            m_color = color;
            m_x = x;
            m_y = y;
            m_visual.setPosition(200 + m_x * 100, 100 + m_y * 100);
            m_visual.setScale(1.8,1.8);
        }
        ~Figures() {};
        short Get_x(){
            return m_x;
        }
        void Set_coord(short x, short y){
            m_x = x;
            m_y = y;
            m_visual.setPosition(200 + m_x * 100,100 + m_y * 100);
        }
        short Get_y(){
            return m_y;
        }
        bool Get_color(){
            return m_color;
        }
        short Get_type(){
            return m_type;
        }
        sf::Sprite Get_piece(){
            return m_visual;
        }
        virtual std::vector<Possibility> can_move(short situation[8][8]){};

        char static place(short el, bool color){
            if (((el > 0) == color) and el != 0){
                // фигура совпадает цветом
                return 'a';
            }
            if (el == 0){
                return 'b';
            }
            // фигура не совпадает цветом, после неё остановиться
            return 'c';
        }
    };

    class Bishop: virtual public Figures{
    private:
        sf::Texture m_image;
    public:
        Bishop(bool color, short x, short y) : Figures(color, x, y) {
            if (color) {
                m_type = 4;
                m_image.loadFromFile("../res/images/bishop1.png");
            } else {
                m_type = -4;
                m_image.loadFromFile("../res/images/bishop.png");
            }
            m_visual.setTexture(m_image);
        }
        std::vector<Possibility> can_move(short situation[8][8]) override{
            m_possibility.clear();
            short x,y;
            x = m_x -1;
            y = m_y -1;
            char check = place(situation[y][x],m_color);
            while (x>=0 and y >=0 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if (check == 'c'){
                    break;
                }
                x--;
                y--;
                check = place(situation[y][x],m_color);
            }
            x = m_x -1;
            y = m_y + 1;
            check = place(situation[y][x],m_color);
            while (x>=0 and y <8 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if (check == 'c'){
                    break;
                }
                x--;
                y++;
                check = place(situation[y][x],m_color);
            }
            x = m_x + 1;
            y = m_y - 1;
            check = place(situation[y][x],m_color);
            while (x<8 and y >=0 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if (check == 'c'){
                    break;
                }
                x++;
                y--;
                check = place(situation[y][x],m_color);
            }
            x = m_x + 1;
            y = m_y + 1;
            check = place(situation[y][x],m_color);
            while (x<8 and y <8 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if (check == 'c'){
                    break;
                }
                x++;
                y++;
                check = place(situation[y][x],m_color);
            }
            for (int i = 0; i < m_possibility.size(); i++){
                if (chess::shakh(situation,m_color)){
                    continue;
                }
                else{
                    m_possibility.erase(m_possibility.begin() + i);
                }
            }
            return m_possibility;
        }
    };
    class Horse: virtual public Figures{
    private:
        sf::Texture m_image;
    public:
        Horse(bool color, short x, short y) : Figures(color, x, y){
            if (color){
                m_type = 5;
                m_image.loadFromFile("../res/images/horse1.png");
            }
            else {
                m_type = -5;
                m_image.loadFromFile("../res/images/horse.png");
            }
            m_visual.setTexture(m_image);
        }
        std::vector<Possibility> can_move(short situation[8][8]) override{
            m_possibility.clear();
            short x,y;
            x = m_x;
            y = m_y;
            if (x + 2 < 8){
                if (y + 1 < 8 and place(situation[y+1][x+2],m_color) != 'a') {
                    m_possibility.push_back(Possibility(x+2,y+1));
                }
                if (y - 1 >= 0  and place(situation[y-1][x+2],m_color) != 'a'){
                    m_possibility.push_back(Possibility(x+2,y-1));
                }
            }
            if (x - 2 >= 0) {
                if (y + 1 < 8 and place(situation[y+1][x-2],m_color) != 'a') {
                    m_possibility.push_back(Possibility(x-2,y+1));
                }
                if (y - 1 >= 0 and place(situation[y-1][x-2],m_color) != 'a') {
                    m_possibility.push_back(Possibility(x-2,y-1));
                }
            }
            if (y + 2 < 8) {
                if (x + 1 < 8 and place(situation[y+2][x+1],m_color) != 'a') {
                    m_possibility.push_back(Possibility(x+1,y+2));
                }
                if (x - 1 >= 0 and place(situation[y+2][x-1],m_color) != 'a') {
                    m_possibility.push_back(Possibility(x-1,y+2));
                }
            }
            if (y - 2 < 8) {
                if (x + 1 < 8 and place(situation[y-2][x+1],m_color) != 'a') {
                    m_possibility.push_back(Possibility(x+1,y-2));
                }
                if (x - 1 >= 0 and place(situation[y-2][x-1],m_color) != 'a') {
                    m_possibility.push_back(Possibility(x-1,y-2));
                }
            }
            for (int i = 0; i < m_possibility.size(); i++){
                if (chess::shakh(situation,m_color)){
                    continue;
                }
                else{
                    m_possibility.erase(m_possibility.begin() + i);
                }
            }
            return m_possibility;
        }
    };
    class Queen: virtual public Figures{
    private:
        sf::Texture m_image;
    public:
        Queen(bool color, short x, short y) : Figures(color, x, y){
            if (color){
                m_type = 2;
                m_image.loadFromFile("../res/images/queen1.png");
            }
            else {
                m_type = -2;
                m_image.loadFromFile("../res/images/queen.png");
            }
            std::cout << "Queen: x = " << m_y << " y = " <<  m_x << std::endl;
            m_visual.setTexture(m_image);
        }
        std::vector<Possibility> can_move(short situation[8][8]) override{
            m_possibility.clear();
            // as bishop
            short x,y;
            x = m_x -1;
            y = m_y -1;
            char check = place(situation[y][x],m_color);
            while (x>=0 and y >=0 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if (check == 'c'){
                    break;
                }
                x--;
                y--;
                check = place(situation[y][x],m_color);
            }
            x = m_x -1;
            y = m_y + 1;
            check = place(situation[y][x],m_color);
            while (x>=0 and y <8 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if (check == 'c'){
                    break;
                }
                x--;
                y++;
                check = place(situation[y][x],m_color);
            }
            x = m_x + 1;
            y = m_y - 1;
            check = place(situation[y][x],m_color);
            while (x<8 and y >=0 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if (check == 'c'){
                    break;
                }
                x++;
                y--;
                check = place(situation[y][x],m_color);
            }
            x = m_x + 1;
            y = m_y + 1;
            check = place(situation[y][x],m_color);
            while (x<8 and y <8 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if (check == 'c'){
                    break;
                }
                x++;
                y++;
                check = place(situation[y][x],m_color);
            }
            // as rook
            x = m_x + 1;
            y = m_y;
            check = place(situation[y][x],m_color);
            while (x < 8 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if(check == 'c'){
                    break;
                }
                x++;
                check = place(situation[y][x],m_color);
            }
            x = m_x - 1;
            y = m_y;
            check = place(situation[y][x],m_color);
            while (x >= 0 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if(check == 'c'){
                    break;
                }
                x--;
                check = place(situation[y][x],m_color);
            }
            x = m_x;
            y = m_y + 1;
            check = place(situation[y][x],m_color);
            while (y < 8 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if(check == 'c'){
                    break;
                }
                y++;
                check = place(situation[y][x],m_color);
            }
            x = m_x;
            y = m_y - 1;
            check = place(situation[y][x],m_color);
            while (y >= 0 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if(check == 'c'){
                    break;
                }
                y--;
                check = place(situation[y][x],m_color);
            }
            for (int i = 0; i < m_possibility.size(); i++){
                if (chess::shakh(situation,m_color)){
                    continue;
                }
                else{
                    m_possibility.erase(m_possibility.begin() + i);
                }
            }
            return m_possibility;
        }
    };
    class Rook: virtual public Figures{
    private:
        sf::Texture m_image;
    public:
        Rook(bool color, short x, short y) : Figures(color, x, y){
            if (color){
                m_type = 3;
                m_image.loadFromFile("../res/images/rook1.png");
            }
            else {
                m_type = -3;
                m_image.loadFromFile("../res/images/rook.png");
            }
            m_visual.setTexture(m_image);
        }
        std::vector<Possibility> can_move(short situation[8][8]) override{
            m_possibility.clear();
            short x,y;
            x = m_x + 1;
            y = m_y;
            char check = place(situation[y][x],m_color);
            while (x < 8 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if(check == 'c'){
                    break;
                }
                x++;
                check = place(situation[y][x],m_color);
            }
            x = m_x - 1;
            y = m_y;
            check = place(situation[y][x],m_color);
            while (x >= 0 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if(check == 'c'){
                    break;
                }
                x--;
                check = place(situation[y][x],m_color);
            }
            x = m_x;
            y = m_y + 1;
            check = place(situation[y][x],m_color);
            while (y < 8 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if(check == 'c'){
                    break;
                }
                y++;
                check = place(situation[y][x],m_color);
            }
            x = m_x;
            y = m_y - 1;
            check = place(situation[y][x],m_color);
            while (y >= 0 and check != 'a'){
                m_possibility.push_back(Possibility(x,y));
                if(check == 'c'){
                    break;
                }
                y--;
                check = place(situation[y][x],m_color);
            }
            for (int i = 0; i < m_possibility.size(); i++){
                if (chess::shakh(situation,m_color)){
                    continue;
                }
                else{
                    m_possibility.erase(m_possibility.begin() + i);
                }
            }
            return m_possibility;
        }
    };
    class King: virtual public Figures{
    private:
        sf::Texture m_image;
    public:
        King(bool color, short x, short y) : Figures(color, x, y){
            if (color){
                m_type = 1;
                m_image.loadFromFile("../res/images/king1.png");
            }
            else {
                m_type = -1;
                m_image.loadFromFile("../res/images/king.png");
            }
            m_visual.setTexture(m_image);
        }
        std::vector<Possibility> can_move(short situation[8][8]) override{
            m_possibility.clear();
            short x,y;
            x = m_x;
            y = m_y;
            char check = place(situation[y][x+1],m_color);
            if (x + 1 < 8 and check != 'a'){
                m_possibility.push_back(Possibility(x+1,y));
            }
            check = place(situation[y+1][x+1],m_color);
            if (x + 1 < 8 and y +1 < 8 and check != 'a'){
                m_possibility.push_back(Possibility(x+1,y+1));
            }
            check = place(situation[y+1][x],m_color);
            if (y + 1 < 8 and check != 'a'){
                m_possibility.push_back(Possibility(x,y+1));
            }
            check = place(situation[y+1][x-1],m_color);
            if (x - 1 >= 0 and y+1 < 8 and check != 'a'){
                m_possibility.push_back(Possibility(x-1,y +1));
            }
            check = place(situation[y][x-1],m_color);
            if (x - 1 >= 0 and check != 'a'){
                m_possibility.push_back(Possibility(x-1,y));
            }
            check = place(situation[y-1][x-1],m_color);
            if (x - 1 >=0 and y -1 >= 0 and check != 'a'){
                m_possibility.push_back(Possibility(x-1,y-1));
            }
            check = place(situation[y-1][x],m_color);
            if (y - 1 >= 0 and check != 'a'){
                m_possibility.push_back(Possibility(x,y-1));
            }
            check = place(situation[y-1][x+1],m_color);
            if (y-1 >= 0 and x + 1 < 8 and check != 'a'){
                m_possibility.push_back(Possibility(x+1,y-1));
            }
            for (int i = 0; i < m_possibility.size(); i++){
                if (chess::shakh(situation,m_color)){
                    continue;
                }
                else{
                    m_possibility.erase(m_possibility.begin() + i);
                }
            }
            return m_possibility;
        }
    };
    class Pawn : virtual public Figures {
    private:
        sf::Texture m_image;
    public:
        Pawn(bool color, short x, short y) : Figures(color, x, y) {
            if (color) {
                m_type = 6;
                m_image.loadFromFile("../res/images/pawn1.png");
            }
            else {
                m_type = -6;
                m_image.loadFromFile("../res/images/pawn.png");
            }
            m_visual.setTexture(m_image);
        }
//        Figures operator=(Figures temp)
//        {
//            this->m_type = temp.Get_type();
//            this->m_visual = temp.Get_piece();
//            this->Set_coord(temp.Get_x(), temp.Get_y());
//            return *this;
//        }
        std::vector<Possibility> can_move(short situation[8][8]) override {
            m_possibility.clear();
            short x, y;
            x = m_x;
            y = m_y;
            char check = place(situation[y][x], m_color);
            if (m_color)
            {
                check = place(situation[y - 1][x], m_color);
                if (y - 1 >= 0 and check == 'b') {
                    m_possibility.push_back(Possibility(x, y - 1));
                    if (y == 6 and (place(situation[y - 2][x], m_color) == 'b'))
                    {
                        m_possibility.push_back(Possibility(x, y - 2));
                    }
                }
                check = place(situation[y - 1][x - 1], m_color);
                if (y - 1 >= 0 and x - 1 >= 0 and check == 'c')
                {
                    m_possibility.push_back(Possibility(x - 1, y - 1));
                }
                check = place(situation[y - 1][x + 1], m_color);
                if (y - 1 >= 0 and x + 1 <8 and check == 'c')
                {
                    m_possibility.push_back(Possibility(x + 1, y - 1));
                }
            }
            if (!m_color)
            {
                check = place(situation[y + 1][x], m_color);
                if (y + 1 <= 7 and check == 'b') {
                    m_possibility.push_back(Possibility(x, y + 1));
                    if (y == 1 and (place(situation[y + 2][x], m_color) == 'b'))
                    {
                        m_possibility.push_back(Possibility(x, y + 2));
                    }
                }
                check = place(situation[y + 1][x - 1], m_color);
                if (y + 1 <= 7 and x - 1 >= 0 and check == 'c')
                {
                    m_possibility.push_back(Possibility(x - 1, y + 1));
                }
                check = place(situation[y + 1][x + 1], m_color);
                if (y + 1 <= 7 and x + 1 < 8 and check == 'c')
                {
                    m_possibility.push_back(Possibility(x + 1, y + 1));
                }
            }
            for (int i = 0; i < m_possibility.size(); i++){
                if (chess::shakh(situation,m_color)){
                    continue;
                }
                else{
                    m_possibility.erase(m_possibility.begin() + i);
                }
            }
            return m_possibility;
        }
    };
}


