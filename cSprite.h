#ifndef CSPRITE_H
#define CSPRITE_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


class cSprite
{
    public:
    bool init(double xPos, double yPos, string sFilename);
    void update(double xPos,double yPos);
    private:
        sf::Sprite _cSprite;
        sf::Texture _texture;
};

#endif // CSPRITE_H
