#include "GameBoard.h"


void GameBoard::nextStage(std::vector<std::string>::const_iterator& cbegin,
                          const std::vector<std::string>::const_iterator& cend) {
    auto stringStream = std::stringstream();

    m_pipeSys.clear();
    m_sources.clear();
    m_numOfTargets = 0;
    m_boardSolved = false;

    // Reads rows and columns.
    stringStream << *cbegin;
    if(!(stringStream >> m_boardSize.x >> m_boardSize.y))
        throw std::invalid_argument("An issue occurred while reading the game board size from the file");

    // Skips to the next line in the file.
    ++cbegin;

    m_pipeSys.resize(m_boardSize.y);

    char type;
    int direction;
    for(auto it = cbegin; it < cend; ++it){

        stringStream.clear();
        stringStream.str("");
        stringStream << *it;

        //Reads pipe type.
        stringStream >> type;
        stringStream.get();

        //Reads degree.
        if(!(stringStream >> direction))
            throw std::invalid_argument("An issue occurred while reading direction of pipe " + std::to_string(std::distance(cbegin, it) + 1));

        addPipe(type, direction);
    }

    initGraph();
}
//=============================================================================
void GameBoard::addPipe(const char type, const int direction) {
    static auto index = 0;

    if(type != NON_PIPE) {
        m_pipeSys[index].push_back(std::make_unique<Pipe>(type, direction, m_boardSize));

        if (type == SOURCE)
            m_sources.emplace_back(index, m_pipeSys[index].size() - 1);
        if (type == SINK)
            m_numOfTargets++;

        // Choose the smallest edge to avoid rectangles in the game board.
        auto squareBound = std::min(BOARD_WIDTH / m_boardSize.x, BOARD_HEIGHT / m_boardSize.y);

        m_pipeSys[index][m_pipeSys[index].size() - 1]->setPosition(
                {BOARD_OFFSET_WIDTH + squareBound * ((float) m_pipeSys[index].size() - 1),
                 BOARD_OFFSET_HEIGHT + squareBound * (float) index});
    }

    else
        m_pipeSys[index].push_back(nullptr);

    if (m_pipeSys[index].size() == m_boardSize.x) {
        ++index;
        if (index == m_boardSize.y)
            index = 0;
    }
}
//=============================================================================
void GameBoard::draw(sf::RenderWindow & window) const{
    for(auto & pipeLine : m_pipeSys)
        for(auto & pipe : pipeLine)
            if(pipe)
                pipe->draw(window);
}
//=============================================================================
bool GameBoard::rotatePipe(const sf::Event & event) { // The function return if any pipe has been rotated.

    // Checks if the tap occurred outside of the game board.
    if(event.mouseButton.y < BOARD_OFFSET_HEIGHT || event.mouseButton.y > WINDOW_HEIGHT - BOARD_OFFSET_HEIGHT ||
        event.mouseButton.x < BOARD_OFFSET_WIDTH || event.mouseButton.x > WINDOW_WIDTH - BOARD_OFFSET_WIDTH)
            return false;

    auto pipeWidth = m_pipeSys[0][0]->getSprite().getGlobalBounds().width;
    auto pipeHeight = m_pipeSys[0][0]->getSprite().getGlobalBounds().height;

    // Calculates the indexes of the pipe that has been tap.
    auto row = int((event.mouseButton.y - BOARD_OFFSET_HEIGHT) / pipeHeight);
    auto col = int((event.mouseButton.x - BOARD_OFFSET_WIDTH) / pipeWidth);

    // For situation that the stage is smaller than the game board area.
    if(row >= m_pipeSys.size() || col >= m_pipeSys[row].size() || !m_pipeSys[row][col] || m_pipeSys[row][col]->getType() == SINK)
        return false;

    if(event.mouseButton.button == sf::Mouse::Left)
        m_pipeSys[row][col]->rotateLeft();
    else if(event.mouseButton.button == sf::Mouse::Right)
        m_pipeSys[row][col]->rotateRight();

    checkConnections({row, col});

    // Hold the all the connected pipe in the stage.
    auto connectedPipe = std::set<boardPosition>();

    for(auto & src : m_sources){
        auto neighbors_found = m_graph.bfs({m_pipeSys[src.first][src.second]->getType(), src});
        connectedPipe.insert(neighbors_found.begin(), neighbors_found.end());
    }

    // Fill connected pipe with water.
    for(auto i = 0; i < m_pipeSys.size(); ++i)
        for(auto j = 0; j < m_pipeSys[i].size(); ++j) {
            if(m_pipeSys[i][j]) {
                if (connectedPipe.find({i, j}) != connectedPipe.end())
                    m_pipeSys[i][j]->connect();
                else
                    m_pipeSys[i][j]->disconnect();
            }
        }

    // Count the number of sink that connected to sources.
    auto counter = std::count_if(connectedPipe.begin(), connectedPipe.end(),
                                 [this](const boardPosition & pos){return m_pipeSys[pos.first][pos.second]->getType() == SINK;});

    // Checks if level is complete.
    if(counter == m_numOfTargets)
        m_boardSolved = true;

    return true;
}
//=============================================================================
bool GameBoard::boardSolved() const{
    return m_boardSolved;
}
//=============================================================================

//----------------------------- Private Functions -----------------------------
void GameBoard::initGraph() {
    m_graph.clear();
    for(auto i = 0; i < m_pipeSys.size(); ++i)
        for(auto j = 0; j < m_pipeSys[i].size(); ++j)
            if (m_pipeSys[i][j])
                checkConnections({i, j});
}
//=============================================================================
void GameBoard::checkConnections(const boardPosition & pos) {
    // Checks connection with nearby pipes.
    if (pos.first - 1 >= 0)
        updateNbr({pos.first, pos.second}, {pos.first - 1, pos.second}, {UP, DOWN});
    if (pos.first + 1 < m_boardSize.y)
        updateNbr({pos.first, pos.second}, {pos.first + 1, pos.second}, {DOWN, UP});
    if (pos.second - 1 >= 0)
        updateNbr({pos.first, pos.second}, {pos.first, pos.second - 1}, {LEFT, RIGHT});
    if (pos.second + 1 < m_boardSize.x)
        updateNbr({pos.first, pos.second}, {pos.first, pos.second + 1}, {RIGHT, LEFT});
}
//=============================================================================
void GameBoard::updateNbr(const boardPosition & fst,
                          const boardPosition & sec, const boardPosition & sides) {
    // For null neighbor.
    if(!m_pipeSys[sec.first][sec.second])
        return;

    // Checks if the pipes are connect.
    if((*m_pipeSys[fst.first][fst.second])[sides.first] && (*m_pipeSys[sec.first][sec.second])[sides.second])
        m_graph.addEdge({(*m_pipeSys[fst.first][fst.second]).getType(), {fst.first, fst.second}},
                        {(*m_pipeSys[sec.first][sec.second]).getType(), {sec.first, sec.second}});

    else
        m_graph.removeEdge({(*m_pipeSys[fst.first][fst.second]).getType(), {fst.first,fst.second}},
                           {(*m_pipeSys[sec.first][sec.second]).getType(), {sec.first,sec.second}});
}
//=============================================================================