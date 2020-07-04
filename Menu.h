#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SoundMusic.h"
using namespace std;

class Menu : public SoundMusic
{
    public:
        Menu(float width, float height);

        void draw(sf::RenderWindow *window);
        void moveup();
        void movedown();
        int GetPressedIteam();




    protected:

    private:
        sf::Font font;
        int selected;
        sf::Text text[2];
         sf::Texture texture;

    sf::Sprite sprite;

};

#endif // MENU_H
