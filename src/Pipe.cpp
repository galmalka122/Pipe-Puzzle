#include "Pipe.h"

Pipe::Pipe(const char type, const int direction, const sf::Vector2i & ratio)
            : m_pipeType(type), m_sourceConnect(false){

    pipeType(type);

    m_pipeEmpty.setOrigin(m_pipeEmpty.getGlobalBounds().width / 2,
                          m_pipeEmpty.getGlobalBounds().height / 2);
    m_pipeFull.setOrigin(m_pipeFull.getGlobalBounds().width / 2,
                         m_pipeFull.getGlobalBounds().height / 2);

    // Choose the smallest edge to avoid rectangles in the game board.
    auto squareBound = std::min(BOARD_WIDTH / ratio.x, BOARD_HEIGHT / ratio.y);


    m_pipeEmpty.setScale({squareBound / m_pipeEmpty.getGlobalBounds().width,
                          squareBound / m_pipeEmpty.getGlobalBounds().height});
    m_pipeFull.setScale({squareBound / m_pipeFull.getGlobalBounds().width,
                         squareBound / m_pipeFull.getGlobalBounds().height});

    initDirection(direction);
}
//=============================================================================
void Pipe::draw(sf::RenderWindow & window) {
    m_sourceConnect ? window.draw(m_pipeFull) : window.draw(m_pipeEmpty);
}
//=============================================================================
sf::Sprite Pipe::getSprite() const {
    if(m_sourceConnect)
        return m_pipeFull;
    else
        return m_pipeEmpty;
}
//=============================================================================
char Pipe::getType() const {
    return m_pipeType;
}
//=============================================================================
void Pipe::setPosition(sf::Vector2f position) {
    m_pipeEmpty.setPosition(position.x + m_pipeEmpty.getGlobalBounds().width / 2,
                            position.y + m_pipeEmpty.getGlobalBounds().height / 2);

    m_pipeFull.setPosition(position.x + m_pipeFull.getGlobalBounds().width / 2,
                            position.y + m_pipeFull.getGlobalBounds().height / 2);
}
//=============================================================================
void Pipe::rotateRight() {
    m_pipeEmpty.rotate(-DEGREE);
    m_pipeFull.rotate(-DEGREE);
    std::swap(m_direction[UP], m_direction[LEFT]);
    std::swap(m_direction[DOWN], m_direction[RIGHT]);
    std::swap(m_direction[UP], m_direction[DOWN]);
}
//=============================================================================
void Pipe::rotateLeft() {
    m_pipeEmpty.rotate(DEGREE);
    m_pipeFull.rotate(DEGREE);
    std::swap(m_direction[UP], m_direction[RIGHT]);
    std::swap(m_direction[DOWN], m_direction[LEFT]);
    std::swap(m_direction[UP], m_direction[DOWN]);
}
//=============================================================================
void Pipe::connect() {
    m_sourceConnect = true;
}
//=============================================================================
void Pipe::disconnect() {
    if(m_pipeType != SOURCE)
        m_sourceConnect = false;
}
//=============================================================================
bool Pipe::operator[](const int side) const {
    if(side < 0 or side > SIDES)
        throw std::domain_error("Each pipe have " + std::to_string(SIDES) + " sides");

    return m_direction[side];
}
//=============================================================================


//----------------------------- Private Functions -----------------------------
void Pipe::pipeType(const char type) {
    switch (type) {
        case SOURCE:
            m_pipeEmpty = Textures::texturesObject().getSprite(SOURCE_F);
            m_pipeFull = Textures::texturesObject().getSprite(SOURCE_F);
            m_direction = SOURCE_SINK_DIRECTION;
            connect();
            break;
        case STRAIGHT:
            m_pipeEmpty = Textures::texturesObject().getSprite(STRAIGHT_E);
            m_pipeFull = Textures::texturesObject().getSprite(STRAIGHT_F);
            m_direction = STRAIGHT_DIRECTION;
            break;
        case CURVED:
            m_pipeEmpty = Textures::texturesObject().getSprite(CURVED_E);
            m_pipeFull = Textures::texturesObject().getSprite(CURVED_F);
            m_direction = CURVED_DIRECTION;
            break;
        case T:
            m_pipeEmpty = Textures::texturesObject().getSprite(T_E);
            m_pipeFull = Textures::texturesObject().getSprite(T_F);
            m_direction = T_DIRECTION;
            break;
        case PLUS:
            m_pipeEmpty = Textures::texturesObject().getSprite(PLUS_E);
            m_pipeFull = Textures::texturesObject().getSprite(PLUS_F);
            m_direction = PLUS_DIRECTION;
            break;
        case SINK:
            m_pipeEmpty = Textures::texturesObject().getSprite(SINK_E);
            m_pipeFull = Textures::texturesObject().getSprite(SINK_F);
            m_direction = SOURCE_SINK_DIRECTION;
            break;
        default:
            throw std::domain_error("No such pipe");
    }
}
//=============================================================================
void Pipe::initDirection(const int direction) {

    if(direction % DEGREE != 0)
        throw std::domain_error("Degree must divided by 90");

    //Calculates the number of rotation in range 0 to 3.
    auto numOfRotate = (direction/DEGREE) % SIDES;

    for(auto i = 0; i < numOfRotate; ++i)
        rotateLeft();
}
//=============================================================================