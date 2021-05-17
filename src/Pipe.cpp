#include "Pipe.h"

Pipe::Pipe(char type, const std::string & direction, const sf::Vector2i & ratio) : m_pipeType(type){

    switch (type) {
        case SOURCE:
            m_sprite = Textures::texturesObject().getSprite(SOURCE_F);
            m_direction = SOURCE_SINK_DIRECTION;
            break;
        case PIPE:
            pipeType(direction);
            break;
        case SINK:
            m_sprite = Textures::texturesObject().getSprite(SINK_E);
            m_direction = SOURCE_SINK_DIRECTION;
            break;
        default:
            throw std::domain_error("");
    }
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2,
                       m_sprite.getGlobalBounds().height / 2);
    m_sprite.setScale({BOARD_WIDTH / (m_sprite.getGlobalBounds().width * ratio.x),
                       BOARD_HEIGHT / (m_sprite.getGlobalBounds().height * ratio.y)});
    initDirection(direction);
}
//=============================================================================
void Pipe::pipeType(const std::string & direction) {

    auto type = PIPES.find(direction);

    if(type == PIPES.end())
        throw std::domain_error("");

    if(type->second == STRAIGHT_HORIZONTAL_P || type->second == STRAIGHT_VERTICAL_P){
        m_sprite = Textures::texturesObject().getSprite(STRAIGHT_E);
        m_direction = STRAIGHT_DIRECTION;
    }
    else if(type->second == CURVED_UP_LEFT_P || type->second == CURVED_UP_RIGHT_P ||
            type->second == CURVED_DOWN_LEFT_P || type->second == CURVED_DOWN_RIGHT_P){
        m_sprite = Textures::texturesObject().getSprite(CURVED_E);
        m_direction = CURVED_DIRECTION;
    }
    else if(type->second == T_UP_P || type->second == T_DOWN_P ||
            type->second == T_LEFT_P || type->second == T_RIGHT_P){
        m_sprite = Textures::texturesObject().getSprite(T_E);
        m_direction = T_DIRECTION;
    }
    else if(type->second == PLUS_P){
        m_sprite = Textures::texturesObject().getSprite(PLUS_E);
        m_direction = PLUS_DIRECTION;
    }
}
//=============================================================================
void Pipe::initDirection(const std::string & direction) {

    std::array<bool, SIDES> temp{};

    for(auto i = 0; i < SIDES; ++i)
        temp[i] = direction[i] == '1';


    while(m_direction != temp){
        rotateRight();
    }
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
        m_sprite.rotate(90);

        std::swap(m_direction[UP], m_direction[RIGHT]);
        std::swap(m_direction[DOWN], m_direction[LEFT]);
        std::swap(m_direction[UP], m_direction[DOWN]);
    }
}
//=============================================================================
void Pipe::rotateLeft() {

    if(m_pipeType != SINK)
        m_sprite.rotate(-90);

    std::swap(m_direction[UP], m_direction[LEFT]);
    std::swap(m_direction[DOWN], m_direction[RIGHT]);
    std::swap(m_direction[UP], m_direction[DOWN]);
}
//=============================================================================