#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Macros.h"
#include "Textures.h"

class Pipe {
public:
    Pipe(char, const std::string &, const sf::Vector2i &);
    void initDirection(const std::string &);
    void draw(sf::RenderWindow &);
    sf::Sprite getSprite() const;
    void setPosition(sf::Vector2f);
    void rotateRight();
    void rotateLeft();

private:
    char m_pipeType;
    sf::Sprite m_sprite;
    std::array<bool, SIDES> m_direction;
    void pipeType(const std::string &);
};