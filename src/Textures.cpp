#include "Textures.h"

Textures::Textures()
{
    m_textures.resize(NUM_OF_TEXTURES);

    m_textures[SOURCE_F].loadFromFile("Source.png");
    m_textures[SINK_E].loadFromFile("Sink.png");
    m_textures[STRAIGHT_E].loadFromFile("Straight.png");
    m_textures[CURVED_E].loadFromFile("Curved.png");
    m_textures[T_E].loadFromFile("T_Pipe.png");
}
//=======================================================================
Textures & Textures::texturesObject(){
    static Textures texturesObject;

    return texturesObject;
}
//=======================================================================
const sf::Sprite Textures::getSprite(enum Textures_t image) {
    return sf::Sprite(m_textures[image]);
}
//=======================================================================