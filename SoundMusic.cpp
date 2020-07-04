#include "SoundMusic.h"


void SoundMusic::playScoringSound()
{
    if (!load.loadFromFile("Beep1.wav"))
        {
            return;
        }

    play.setBuffer(load);

    play.play();


}

void SoundMusic::playBGMusic(const std::string& s)
{
    if (!bgMusic.openFromFile(s))
    {
        return;

    }

    bgMusic.play();
//
}
void SoundMusic::playCollisionSound()
{
    if (!load.loadFromFile("Beep1.wav"))
    {
        return;
    }

    play.setBuffer(load);

    play.play();

}
void SoundMusic::stop()
{
    bgMusic.stop();
}

