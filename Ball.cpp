#include "Ball.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <sstream>
#include "SoundMusic.h"
#include <SFML/Audio.hpp>
using namespace std;
void Ball::BallRender(sf::RenderWindow *window)
{
    window->draw(_sprite);

}
void Ball::BallInit(double x, double y, string sfilename)
{
    _texture.loadFromFile(sfilename);
    _sprite.setTexture(_texture);
   _sprite.setPosition(x,y);
    xpos = _sprite.getPosition().y/2;
    xdir= 1;
    ydir=1;
    speed = 8;
   angle =0.0;
   score1=0;
   score2=0;
}
void Ball::BallMove(double Delapsed)
{
   _sprite.move(cos(angle)*Delapsed*xdir*speed,sin(angle)*Delapsed*ydir*speed);
}
void Ball::Ballcollision()
{
    if(_sprite.getPosition().x<0)
    {
        ResetBall();
         score2++;
        sound.playScoringSound();
    }
    else if(_sprite.getPosition().x>1280)
    {
        ResetBall();
            score1++;
        sound.playScoringSound();
    }
    else if(_sprite.getPosition().y<0)
    {
        ydir = changedir(ydir);
;       sound.playCollisionSound();
    }
    else if(_sprite.getPosition().y>690)
    {
         ydir = changedir(ydir);
         sound.playCollisionSound();
    }

}
int Ball::changedir(int dir)
{
    dir*=-1;
    return dir;
}
void Ball::BallPaddleColl(sf::Vector2f paddle , sf::FloatRect paddlebounds)
{
    /// here I declare variable in order to better recognize my paddle sprite dimensions
    bool collide;
     float bottom = _sprite.getPosition().y+_sprite.getLocalBounds().height;
        float top = _sprite.getPosition().y;
        float left = _sprite.getPosition().x;
        float right = _sprite.getPosition().x + _sprite.getLocalBounds().width;

        float paddleRight = paddle.x + paddlebounds.width;
        float paddleLeft = paddle.x;
        float paddleTop = paddle.y;
        float paddleBottom = paddle.y + paddlebounds.height;

        float parts = (paddle.y+paddlebounds.height/8);


    if(left < paddleRight && top < paddleBottom && bottom > paddleTop   && right > paddleRight)
    {
        /// when a collision happens collide will be set to true and speed will amp up
        collide = true;

        speed+=.5;
        sound.playCollisionSound();
    }
    /// Here I basically divided up the paddle into 8 sections. Depending where the ball collides it changes the angle respect to it. I used the pi circle to determine the angles
       if(collide && top < parts * 1 && bottom  > paddle.y)
        {
           angle = -(3.14/4);
            xdir = changedir(xdir);
        }
        else if(collide && top < parts+13.625 && bottom  > parts)
        {
           angle = -3.14/6;
           xdir = changedir(xdir);
        }
        else if(collide && top < parts+27.25 && bottom  > parts+13.625 )
        {

            angle = -3.14/12;
             xdir = changedir(xdir);
        }
        else if(collide && top < parts+40.875 && bottom  > parts+27.25)
        {

            angle = -3.14/24;
            xdir = changedir(xdir);
        }
        else if(collide && top < parts +54.5 && bottom  > parts + 40.875)
        {
            angle = 3.14/24;
             xdir = changedir(xdir);
        }
         else if(collide && top < parts + 68.125 && bottom  > parts + 54.5)
        {
            angle = 3.14/12;
             xdir = changedir(xdir);
        }
         else if(collide && top < parts + 81.75 && bottom  > parts + 68.125)
        {
            angle = 3.14/6;
             xdir = changedir(xdir);
        }
         else if(collide && top < parts+95.375 && bottom  > parts + 81.75)
        {
            angle = 3.14/4;
             xdir = changedir(xdir);
        }



}
void Ball::BallPaddleColl2(sf::Vector2f paddle, sf::FloatRect paddlebounds)
{
    bool collide;

     float bottom2 = _sprite.getPosition().y+_sprite.getLocalBounds().height;
        float top2 = _sprite.getPosition().y;
        float left2 = _sprite.getPosition().x;
        float right2 = _sprite.getPosition().x + _sprite.getLocalBounds().width;

        float paddleRight2 = paddle.x + paddlebounds.width;
        float paddleLeft2 = paddle.x;
        float paddleTop2 = paddle.y;
        float paddleBottom2 = paddle.y + paddlebounds.height;

        float parts2 = (paddle.y+paddlebounds.height/8);


     if(right2 > paddleLeft2 && top2 < paddleBottom2 && bottom2 > paddleTop2 && left2 < paddleLeft2)
     {
         collide = true;
        speed+=.5;
        sound.playCollisionSound();

     }
      if(collide && top2 < parts2 * 1 && bottom2  > paddle.y)
        {
           angle = -(3.14/4);
            xdir = changedir(xdir);
        }
        else if(collide && top2 < parts2+13.625 && bottom2  > parts2)
        {
           angle = -3.14/6;
            xdir = changedir(xdir);
        }
        else if(collide && top2 < parts2+27.25 && bottom2  > parts2+13.625 )
        {
            angle = -3.14/12;
             xdir = changedir(xdir);
        }
        else if(collide && top2 < parts2+40.875 && bottom2  > parts2+27.25)
        {
            angle = -3.14/24;
             xdir = changedir(xdir);
        }
        else if(collide && top2 < parts2 +54.5 && bottom2  > parts2 + 40.875)
        {
            angle = 3.14/24;
             xdir = changedir(xdir);
        }
         else if(collide && top2 < parts2 + 68.125 && bottom2  > parts2 + 54.5)
        {
            angle = 3.14/12;
             xdir = changedir(xdir);
        }
         else if(collide && top2 < parts2 + 81.75 && bottom2  > parts2 + 68.125)
        {
            angle = 3.14/6;
             xdir = changedir(xdir);
        }
         else if(collide && top2 < parts2+95.375 && bottom2  > parts2 + 81.75)
        {
            angle = 3.14/4;
             xdir = changedir(xdir);
        }



}

void Ball::randomangle()
{
    angle = 0;

}
void Ball::ResetBall()
{

    _sprite.setPosition(640,360);
    speed=8;
    randomangle();

}
string Ball::Getscore1()
{
    /// conversion to string in order to pass in score text function in main
    int Rscore1 = score1;
    stringstream ss1;
    ss1 << Rscore1 <<endl;
    string Score1 = ss1.str();
        return Score1;

}
string Ball::Getscore2()
{

    int Rscore2 = score2;
    stringstream ss2;
    ss2 << Rscore2 <<endl;
    string Score2 = ss2.str();

    return Score2;


}
