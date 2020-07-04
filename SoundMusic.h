#ifndef SoundMusic_hpp
#define SoundMusic_hpp

#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

class SoundMusic
{
private:

    sf::SoundBuffer load;
    sf::Sound play;
    sf::Music bgMusic;


public:

    void playScoringSound();
    void playCollisionSound();
    void playBGMusic(const std::string&);
    void stop();

};


#endif /* SoundMusic_hpp */
