#pragma once

#include <sstream>
#include <vector>
#include "Pipe.h"
#include "File.h"

class GameBoard {
public:
    GameBoard();
    void addPipe(const char, const int);
    void draw(sf::RenderWindow &);
    void nextStage();
    void rotatePipe(const sf::Event &);

private:
    File m_stagesFile;
    sf::Vector2i m_boardSize;
    std::vector<std::vector<std::unique_ptr<Pipe>>> m_pipeSys;
};
