#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Menu.h"
#include "Player.h"
#include <string>
#include <sstream>
#include "DisplayScore.h"
#include "SoundMusic.h"
#include <SFML/Audio.hpp>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Extreme Pong",sf::Style::Close | sf::Style::Resize);
    sf::Texture Background;
    Background.loadFromFile("Background.png");
    sf::Sprite background1;
    background1.setTexture(Background);
    sf::Font font;
    sf::Text ScoreText, ScoreText2, Player1Win, Player2Win;
    font.loadFromFile("SoccerLeague.ttf");
    ScoreText.setString("Score: ");
    ScoreText.setFont(font);
    ScoreText.setPosition(100,10);
    ScoreText.setCharacterSize(60);
    ScoreText.setColor(sf::Color::White);
     ScoreText2.setString("Score: ");
    ScoreText2.setFont(font);
    ScoreText2.setPosition(900,10);
    ScoreText2.setCharacterSize(60);
    ScoreText2.setColor(sf::Color::White);

    Player1Win.setString("Player 1 Wins: Press R\n\t\tto Play Again");
    Player1Win.setFont(font);
    Player1Win.setCharacterSize(70);
    Player1Win.setPosition(300,300);
    Player1Win.setColor(sf::Color::Red);
    Player2Win.setString("Player 2 Wins: Press R\n\tto Play Again");
    Player2Win.setFont(font);
    Player2Win.setCharacterSize(70);
    Player2Win.setPosition(300,300);
    Player2Win.setColor(sf::Color::Blue);




    DisplayScore score, score2;
    Player p1, p2;
    Ball ball;
    Menu menu(window.getSize().x,window.getSize().y);
    p1.init(45,300, "Paddle.png");
    p2.init(1230,300, "Paddle2.png");
    score.initializer("SoccerLeague.ttf", 300,10);
    score2.initializer("SoccerLeague.ttf", 1100 , 10);
    ball.BallInit(640,360,"Ball.png");

    double elapsed=0;
    sf::Clock clock;
    clock.restart();

    bool play = false;

    SoundMusic music;
    music.playBGMusic("StromOwl.ogg");

    while(window.isOpen())
{

        sf::Event evnt;


        while(window.pollEvent(evnt))
    {
        switch(evnt.type)
            {
        case sf::Event::KeyReleased:
            switch(evnt.key.code)
            {
            case sf::Keyboard::Up:
                menu.moveup();
                break;
            case sf::Keyboard::Down:
                menu.movedown();
                break;
//            case sf::Keyboard::Escape:
//                play = false;
//                break;
//            case sf::Keyboard::R:
//                ball.ResetBall();
//                ball.score1=0;              ///When player chooses to restart a game the players reset and ball and score
//                ball.score2=0;
//                p1.init(45,300, "Paddle.png");
//                p2.init(1230,300, "Paddle2.png");
//                break;

            case sf::Keyboard::Return:
                switch(menu.GetPressedIteam())
                {
                case 0:
                    play = true;
                    ball.score1=-1; ///score is set to -1 due to a bug that when the menu is loaded  p1 automaticallly scores
                    music.stop();
                    break;
                case 1:
                    window.close();
                    break;
                }
            }
            break;

            case sf::Event::Closed:
                window.close();
                break;
            }
    }

    /// game looop

        window.clear();

        while(play)
        {


            window.draw(background1);
            p1.draw(&window);
            p2.draw(&window);
            ball.BallRender(&window);
            window.draw(ScoreText);
            window.draw(ScoreText2);
            score.draw(&window);
            score2.draw(&window);
            p1.move();
            p2.move2();
            ball.BallMove(elapsed);
            p1.check_Border_Col(720);
            p2.check_Border_Col(720);
            ball.Ballcollision();
            score.updatescore(ball.Getscore1());
            score2.updatescore(ball.Getscore2());
            ball.BallPaddleColl(p1.Getposition(),p1.GetlocalBounds());
            ball.BallPaddleColl2(p2.Getposition(),p2.GetlocalBounds());
            if(ball.score1 >= 10)
            {
                window.draw(Player1Win);
                ball.ResetBall();
            }
            if(ball.score2 >=10)
            {
                window.draw(Player2Win);
                ball.ResetBall();
            }
            window.display();
            elapsed = clock.getElapsedTime().asMicroseconds()/10000.f;
            clock.restart();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                play = false;
                 music.playBGMusic("StromOwl.ogg");
            }
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                 ball.ResetBall();
                ball.score1=0;              ///When player chooses to restart a game the players reset and ball and score
                ball.score2=0;
                p1.init(45,300, "Paddle.png");
                p2.init(1230,300, "Paddle2.png");

            }


        }
        /// menu.

        if(!play)
        {

            ball.score1 = 0;
            ball.score2 = 0;
            menu.draw(&window);
            ball.ResetBall();
            ball.BallInit(640,360,"Ball.png");  /// This is to keep the ball from moving when the menu issum up
            p1.init(45,360, "Paddle.png");
            p2.init(1230,360, "Paddle2.png");
            window.display();

        }
}
        return 0;
}




