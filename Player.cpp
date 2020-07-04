#include "Player.h"
#include<SFML/Graphics.hpp>
#include <iostream>

void Player::init(int x, int y, string filename)
{
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
}
void Player::draw(sf::RenderWindow* window)
{
    window -> draw(sprite);
}
void Player::move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))                 //For player 1 up
    {
        sprite.move(0, -2.5);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))                 //For player 1 down
    {
        sprite.move(0, 2.5);
    }
}
void Player::move2()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))                 //For player 2 up
    {
        sprite.move(0, -2.5);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))                 //For player 2 down
    {
        sprite.move(0, 2.5);
    }
}
sf::Vector2f Player::Getposition()
{
    return sprite.getPosition();
}

void Player::check_Border_Col(int border_Y)
{
    if(sprite.getPosition().y < border_Y -720 )                         //Top bound
    {
        sprite.setPosition(sprite.getPosition().x , 1);
    }
    if(sprite.getPosition().y + sprite.getLocalBounds().height > border_Y)              //Bottom Bound
    {
        sprite.setPosition(sprite.getPosition().x , border_Y - sprite.getLocalBounds().height);
    }
}
sf::FloatRect Player::GetlocalBounds()
{
    return sprite.getLocalBounds();
}
