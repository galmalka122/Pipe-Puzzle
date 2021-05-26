#include "StageDetails.h"

StageDetails::StageDetails() : m_title("", Font::FontObject().getFont()), m_counter(0), m_stage(0){
    m_title.setPosition(WINDOW_WIDTH / 2 , BOARD_OFFSET_HEIGHT / 2);
    m_title.setCharacterSize(CHARACTER_SIZE);
    m_title.setFillColor(sf::Color::Black);
}
//=============================================================================
void StageDetails::initTap() {
    m_counter = 0;
    setTitle();
}
//=============================================================================
void StageDetails::increaseStage() {
    ++m_stage;
    setTitle();
}
//=============================================================================
void StageDetails::tap() {
    ++m_counter;
    setTitle();
}
//=============================================================================
void StageDetails::draw(sf::RenderWindow & window) const {
    window.draw(m_title);
}
//=============================================================================
void StageDetails::setTitle() {
    m_title.setString("Level = " + std::to_string(m_stage) + " Tap Counter = " + std::to_string(m_counter));
    m_title.setOrigin(WINDOW_WIDTH / 2, BOARD_OFFSET_HEIGHT / 2);
    m_title.setPosition(WINDOW_WIDTH/2 , BOARD_OFFSET_HEIGHT / 2);
}
//=============================================================================
