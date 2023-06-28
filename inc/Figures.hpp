#include <SFML/Graphics.hpp>
#include <iostream>
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
    };

    class Bishop: public Figures{
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
        bool can_move(){
            return 1;
        }
    };
    class Horse: public Figures{
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
    };
    class Queen: public Figures{
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
    class Rook: public Figures{
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
    class King: public Figures{
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
    class Pawn: public Figures{
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


