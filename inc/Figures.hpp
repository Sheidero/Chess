#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
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
    };

    class Figures{
    private:
        // 0 - чёрные, 1 - белые
        bool m_color;
        // 1 - Короли, 2 - Ферзи, 3 - Ладьи, 4 - Слоны, 5 - Кони, 6 - пешки
        char m_type;
    protected:
        sf::Sprite m_visual;
        short m_x;
        short m_y;
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
        sf::Sprite Get_piece(){
            return m_visual;
        }
        virtual std::vector<Possibility> can_move(){};
    };

    class Bishop: virtual public Figures{
    private:
        sf::Texture m_image;
    public:
        Bishop(bool color, short x, short y) : Figures(color, x, y) {
            if (color) {
                m_image.loadFromFile("../res/images/bishop1.png");
            } else {
                m_image.loadFromFile("../res/images/bishop.png");
            }
            m_visual.setTexture(m_image);
        }
        std::vector<Possibility> can_move() override{
            short x,y;
            x = m_x -1;
            y = m_y -1;
            Possibility circle(x,y);
            while (x>=0 and y >=0){
                m_possibility.push_back(circle);
                x--;
                y--;
                circle.Set_coord(x,y);
            }
            x = m_x -1;
            y = m_y + 1;
            circle.Set_coord(x,y);
            while (x>=0 and y <8){
                m_possibility.push_back(circle);
                x--;
                y++;
                circle.Set_coord(x,y);
            }

            x = m_x + 1;
            y = m_y - 1;
            circle.Set_coord(x,y);
            while (x<8 and y >=0){
                m_possibility.push_back(circle);
                x++;
                y--;
                circle.Set_coord(x,y);
            }

            x = m_x + 1;
            y = m_y + 1;
            circle.Set_coord(x,y);
            while (x<8 and y <8){
                m_possibility.push_back(circle);
                x++;
                y++;
                circle.Set_coord(x,y);
            }
            std::cout << sizeof m_possibility << std::endl;
            return m_possibility;
        }
    };
    class Horse: virtual public Figures{
    private:
        sf::Texture m_image;
    public:
        Horse(bool color, short x, short y) : Figures(color, x, y){
            if (color){
                m_image.loadFromFile("../res/images/horse1.png");
            }
            else {
                m_image.loadFromFile("../res/images/horse.png");
            }
            m_visual.setTexture(m_image);
        }
        std::vector<Possibility> can_move() override{
            short x,y;
            x = m_x;
            y = m_y;
            Possibility circle(x,y);
            if (x + 2 < 8){
                if (y + 1 < 8) {
                    circle.Set_coord(x + 2, y + 1);
                    m_possibility.push_back(circle);
                }

            }
        }
    };
    class Queen: virtual public Figures{
    private:
        sf::Texture m_image;
    public:
        Queen(bool color, short x, short y) : Figures(color, x, y){
            if (color){
                m_image.loadFromFile("../res/images/queen1.png");
            }
            else {
                m_image.loadFromFile("../res/images/queen.png");
            }
            m_visual.setTexture(m_image);
        }
    };
    class Rook: virtual public Figures{
    private:
        sf::Texture m_image;
    public:
        Rook(bool color, short x, short y) : Figures(color, x, y){
            if (color){
                m_image.loadFromFile("../res/images/rook1.png");
            }
            else {
                m_image.loadFromFile("../res/images/rook.png");
            }
            m_visual.setTexture(m_image);
        }
    };
    class King: virtual public Figures{
    private:
        sf::Texture m_image;
    public:
        King(bool color, short x, short y) : Figures(color, x, y){
            if (color){
                m_image.loadFromFile("../res/images/king1.png");
            }
            else {
                m_image.loadFromFile("../res/images/king.png");
            }
            m_visual.setTexture(m_image);
        }
    };
    class Pawn: virtual public Figures{
    private:
        sf::Texture m_image;
    public:
        Pawn(bool color, short x, short y) : Figures(color, x, y){
            if (color){
                m_image.loadFromFile("../res/images/pawn1.png");
            }
            else {
                m_image.loadFromFile("../res/images/pawn.png");
            }
            m_visual.setTexture(m_image);
        }
    };
}


