#pragma once

#include <SFML/Audio.hpp>
#include <memory>

#include "Macros.h"
#include "FileError.h"

class Sound {

public:
    static Sound & soundObject();
    void playSound(enum Sounds_t);
    void stopSound(enum Sounds_t);
    bool checkSoundPlay(enum Sounds_t);

private:
    //--------------------Constructor/Destructor Section--------------------
    Sound();
    Sound(const Sound &) = default;
    Sound & operator=(const Sound &) = default;


    std::vector<sf::SoundBuffer> m_soundBuffer;
    std::vector<sf::Sound> m_sounds;
};