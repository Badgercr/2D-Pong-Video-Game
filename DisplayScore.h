#ifndef DISPLAYSCORE_H
#define DISPLAYSCORE_H
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;


class DisplayScore
{
    public:
        void draw(sf::RenderWindow *window);
        void initializer(string filename, int x, int y);
        void updatescore(string score);

    protected:

    private:
        sf::Font font;
        sf::Text score;
};

#endif // DISPLAYSCORE_H
