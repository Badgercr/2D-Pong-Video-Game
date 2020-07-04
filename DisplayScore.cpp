#include "DisplayScore.h"
#include <iostream>

void DisplayScore::draw(sf::RenderWindow* window)
{
    window->draw(score);
}
void DisplayScore::initializer(string filename, int x, int y)
{
    font.loadFromFile(filename);
    score.setFont(font);
    score.setColor(sf::Color::White);
    score.setCharacterSize(60);
    score.setPosition(x,y);

}
void DisplayScore::updatescore(string score)
{
    this->score.setString(score);
}
