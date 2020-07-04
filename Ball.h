#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "SoundMusic.h"
#include <SFML/Audio.hpp>

using namespace std;


class Ball
{
    public:

    void BallRender(sf::RenderWindow *window);
    void BallInit(double x, double y, string sfilename);
    void BallMove(double Delapsed);
    void Ballcollision();
    void BallPaddleColl(sf::Vector2f paddle, sf::FloatRect paddlebounds);
    void randomangle();
    void ResetBall();
    void BallPaddleColl2(sf::Vector2f paddle, sf::FloatRect paddlebounds);
    int score1, score2;
    string Getscore1();
    string Getscore2();

    protected:

    private:
        double Delapsed;
        sf::Sprite _sprite;
        sf::Texture _texture;
        int xdir;   //ballspeed.x
        int ydir; //ballspeed.y
        double angle;
        sf::Clock clock;
        int changedir(int dir);
        float xpos;
        double speed;
        SoundMusic sound;



};

#endif // BALL_H
