#pragma once

#include <cstdlib>

#include "File.h"
#include "Sound.h"
#include "Macros.h"
#include "GameBoard.h"
#include "StageDetails.h"

// A class that manage the game and controls the interaction between the objects in the game.

class GameController {
public:
    GameController();
    void run();

private:
    File m_stageFile;
    GameBoard m_gameBoard;
    sf::Sprite m_backGround;
    StageDetails m_stageDetail;

    void draw(sf::RenderWindow &);
    void nextStage(sf::RenderWindow &);
    void win(sf::RenderWindow &, const enum Textures_t, const enum Sounds_t, const int);
};