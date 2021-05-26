#include "Textures.h"

Textures::Textures(){
    m_textures.resize(NUM_OF_TEXTURES);

    if(!m_textures[BACKGROUND].loadFromFile("BackGround.png"))
        throw FileError("BackGround.png is missing");
    if(!m_textures[WIN_SCREEN].loadFromFile("WinScreen.png"))
        throw FileError("WinScreen.png is missing");
    if(!m_textures[LEVEL_UP].loadFromFile("LevelUP.png"))
        throw FileError("LevelUP.png is missing");
    if(!m_textures[SOURCE_F].loadFromFile("Source.png"))
        throw FileError("Source.png is missing");
    if(!m_textures[SINK_E].loadFromFile("Sink_E.png"))
        throw FileError("Sink_E.png is missing");
    if(!m_textures[SINK_F].loadFromFile("Sink_F.png"))
        throw FileError("Sink_F.png is missing");
    if(!m_textures[STRAIGHT_E].loadFromFile("Straight_E.png"))
        throw FileError("Straight_E.png is missing");
    if(!m_textures[STRAIGHT_F].loadFromFile("Straight_F.png"))
        throw FileError("Straight_F.png is missing");
    if(!m_textures[CURVED_E].loadFromFile("Curved_E.png"))
        throw FileError("Curved_E.png is missing");
    if(!m_textures[CURVED_F].loadFromFile("Curved_F.png"))
        throw FileError("Curved_F.png is missing");
    if(!m_textures[T_E].loadFromFile("T_Pipe_E.png"))
        throw FileError("T_Pipe_E.png is missing");
    if(!m_textures[T_F].loadFromFile("T_Pipe_F.png"))
        throw FileError("T_Pipe_F.png is missing");
    if(!m_textures[PLUS_E].loadFromFile("Plus_E.png"))
        throw FileError("Plus_E.png is missing");
    if(!m_textures[PLUS_F].loadFromFile("Plus_F.png"))
        throw FileError("Plus_F.png is missing");
}
//=============================================================================
Textures & Textures::texturesObject(){
    static Textures texturesObject;

    return texturesObject;
}
//=============================================================================
const sf::Sprite Textures::getSprite(enum Textures_t image) {
    return sf::Sprite(m_textures[image]);
}
//=============================================================================