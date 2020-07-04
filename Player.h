#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

class Player
{
    public:
        void init(int x, int y, string filename);
        void draw(sf::RenderWindow* window);
        void move();
        void move2();

        sf::Vector2f Getposition();
        sf::FloatRect GetlocalBounds();
        void check_Border_Col(int y);



    protected:

    private:
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif // PLAYER_H
