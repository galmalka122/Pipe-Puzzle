#include "Sound.h"

Sound::Sound(){
    m_soundBuffer.resize(NUM_OF_SOUNDS);
    m_sounds.resize(NUM_OF_SOUNDS);

    //---Load Sounds Section---
    if(!m_soundBuffer[WIN_SOUND].loadFromFile("WinSound.wav"))
        throw FileError("WinSound.wav is missing");
    m_sounds[WIN_SOUND].setBuffer(m_soundBuffer[WIN_SOUND]);

    if(!m_soundBuffer[CLICK_SOUND].loadFromFile("Click.wav"))
        throw FileError("Click.wav is missing");
    m_sounds[CLICK_SOUND].setBuffer(m_soundBuffer[CLICK_SOUND]);

    if(!m_soundBuffer[LEVEL_UP_SOUND].loadFromFile("LevelUP.wav"))
        throw FileError("LevelUP.wav is missing");
    m_sounds[LEVEL_UP_SOUND].setBuffer(m_soundBuffer[LEVEL_UP_SOUND]);
}
//=============================================================================
Sound &Sound::soundObject() {
    static Sound soundObject;

    return soundObject;
}
//=============================================================================
void Sound::playSound(enum Sounds_t sound){
    m_sounds[sound].play();
    m_sounds[sound].setVolume(VOLUME * 2);
}
//=============================================================================
void Sound::stopSound(enum Sounds_t sound) {
    if(checkSoundPlay(sound))
        m_sounds[sound].stop();
}
//=============================================================================
bool Sound::checkSoundPlay(enum Sounds_t sound) {

    if(m_sounds[sound].getStatus() == m_sounds[sound].Playing)
        return true;

    return false;
}
//=============================================================================