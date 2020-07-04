#include "Menu.h"
#include <SFML/Graphics.hpp>

Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("SoccerLeague.ttf"))
    {
        cout << "cant open text file" << endl;
    }

    texture.loadFromFile("Pong.png");
    sprite.setTexture(texture);


    text[0].setFont(font);
    text[0].setColor(sf::Color::White);
    text[0].setString("Play (2 Players only)");
    text[0].setPosition(sf::Vector2f(width / 2.5 , height / 3 * 1));
    text[0].setCharacterSize(50);

    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("Quit");
    text[1].setPosition(sf::Vector2f(width / 2.5 , height / 3 * 2));
    text[1].setCharacterSize(50);

    selected = 0;

}
void Menu::draw(sf::RenderWindow *window)
{
    window->draw(sprite);
    for(int i = 0;i <2;i++)
    {
        window->draw(text[i]);
    }


}
void Menu::moveup()
{

    if(selected -1 >=0)
    {
        text[selected].setColor(sf::Color::White);
        selected--;
        text[selected].setColor(sf::Color::Yellow);
    }


}
void Menu::movedown()
{

    if(selected +1 <2)
    {
        text[selected].setColor(sf::Color::White);
        selected++;
        text[selected].setColor(sf::Color::Yellow);
    }


}
int Menu::GetPressedIteam()
{
    return selected;
}

