#pragma once

#include <SFML/Graphics.hpp>

#include "Macros.h"
#include "Font.h"

// A class that represent all the stage details.

class StageDetails {
public:
    StageDetails();
    void initTap();
    void increaseStage();
    void tap();
    void draw(sf::RenderWindow &) const;

private:
    int m_stage;
    int m_counter;
    sf::Text m_title;

    void setTitle();
};