#include "Pipe.h"

Pipe::Pipe(const char type, const int direction, const sf::Vector2i & ratio) : m_pipeType(type){

    pipeType(type);
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2,
                       m_sprite.getGlobalBounds().height / 2);
    m_sprite.setScale({BOARD_WIDTH / (m_sprite.getGlobalBounds().width * ratio.x),
                       BOARD_HEIGHT / (m_sprite.getGlobalBounds().height * ratio.y)});
    initDirection(direction);
}
//=============================================================================
void Pipe::pipeType(const char type) {
    switch (type) {
        case SOURCE:
            m_sprite = Textures::texturesObject().getSprite(SOURCE_F);
            m_direction = SOURCE_SINK_DIRECTION;
            break;
        case STRAIGHT:
            m_sprite = Textures::texturesObject().getSprite(STRAIGHT_E);
            m_direction = STRAIGHT_DIRECTION;
            break;
        case CURVED:
            m_sprite = Textures::texturesObject().getSprite(CURVED_E);
            m_direction = CURVED_DIRECTION;
            break;
        case T:
            m_sprite = Textures::texturesObject().getSprite(T_E);
            m_direction = T_DIRECTION;
            break;
        case PLUS:
            m_sprite = Textures::texturesObject().getSprite(PLUS_E);
            m_direction = PLUS_DIRECTION;
            break;
        case SINK:
            m_sprite = Textures::texturesObject().getSprite(SINK_E);
            m_direction = SOURCE_SINK_DIRECTION;
            break;
        default:
            throw std::domain_error("");
    }
}
//=============================================================================
void Pipe::initDirection(const int direction) {

    if(direction % DEGREE != 0)
        throw std::domain_error("");

    m_sprite.rotate(direction);
}
//=============================================================================
void Pipe::draw(sf::RenderWindow & window) {
    window.draw(m_sprite);
}
//=============================================================================
sf::Sprite Pipe::getSprite() const {
    return m_sprite;
}
//=============================================================================
void Pipe::setPosition(sf::Vector2f position) {
    m_sprite.setPosition(position.x + m_sprite.getGlobalBounds().width/2,
                         position.y + m_sprite.getGlobalBounds().height/2);
}
//=============================================================================
void Pipe::rotateRight() {
    if(m_pipeType != SINK) {
        m_sprite.rotate(DEGREE);

        std::swap(m_direction[UP], m_direction[RIGHT]);
        std::swap(m_direction[DOWN], m_direction[LEFT]);
        std::swap(m_direction[UP], m_direction[DOWN]);
    }
}
//=============================================================================
void Pipe::rotateLeft() {

    if(m_pipeType != SINK)
        m_sprite.rotate(-DEGREE);

    std::swap(m_direction[UP], m_direction[LEFT]);
    std::swap(m_direction[DOWN], m_direction[RIGHT]);
    std::swap(m_direction[UP], m_direction[DOWN]);
}
//=============================================================================