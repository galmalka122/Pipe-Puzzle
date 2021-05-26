#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "Macros.h"
#include "Textures.h"

// A class that represent a pipe.

class Pipe {
public:
    Pipe(const char, const int, const sf::Vector2i &);
    void draw(sf::RenderWindow &);

    sf::Sprite getSprite() const;
    char getType() const;

    void setPosition(sf::Vector2f);
    void rotateRight();
    void rotateLeft();

    void connect();
    void disconnect();

    bool operator[](const int) const;
private:
    char m_pipeType;
    bool m_sourceConnect;
    sf::Sprite m_pipeEmpty;
    sf::Sprite m_pipeFull;
    std::array<bool, SIDES> m_direction; // Indicates the pipe direction.

    void initDirection(const int);
    void pipeType(const char);
};