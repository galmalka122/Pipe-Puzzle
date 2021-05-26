#pragma once

#include <sstream>
#include <vector>
#include <set>

#include "Graph.h"
#include "Pipe.h"

// A class that represent a game board.

class GameBoard {
public:
    GameBoard() = default;
    void addPipe(const char, const int);
    void draw(sf::RenderWindow &) const;
    void nextStage(std::vector<std::string>::const_iterator &, const std::vector<std::string>::const_iterator&);
    bool rotatePipe(const sf::Event &);
    bool boardSolved() const;

private:
    using boardPosition = std::pair<int, int>;

    int m_numOfTargets;
    bool m_boardSolved = false;
    sf::Vector2i m_boardSize;
    std::vector<boardPosition> m_sources;
    Graph<std::pair<char,boardPosition>> m_graph;
    std::vector<std::vector<std::unique_ptr<Pipe>>> m_pipeSys;

    void initGraph();
    void checkConnections(const boardPosition &);
    void updateNbr(const boardPosition &,
                   const boardPosition &,
                   const boardPosition &);
};