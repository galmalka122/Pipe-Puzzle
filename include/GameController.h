#pragma once

#include "GameBoard.h"


class GameController {
public:
    void run();

private:
    GameBoard m_gameBoard;
    void draw(sf::RenderWindow &);
};