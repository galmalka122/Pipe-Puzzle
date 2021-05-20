#include "GameBoard.h"
 GameBoard::GameBoard() : m_stagesFile(STAGES_FILE){
    nextStage();
}
//=============================================================================
void GameBoard::nextStage() {
    m_pipeSys.clear();
    auto stringStream = std::stringstream();

    //Reads rows and columns from file.
    stringStream << m_stagesFile.getLine();
    stringStream >> m_boardSize.x >> m_boardSize.y;

    m_pipeSys.resize(m_boardSize.y);

    char type;
    int direction;
    for(auto i = 0; i < m_boardSize.x * m_boardSize.y; ++i){
        //Skips to the next line in the file.
        ++m_stagesFile;
        stringStream.clear();
        stringStream.str("");
        stringStream << m_stagesFile.getLine();
        stringStream >> type;
        stringStream.get();
        stringStream >> direction;
        addPipe(type, direction);
    }
}
//=============================================================================
void GameBoard::addPipe(const char type, const int direction) {
    static auto index = 0;

    m_pipeSys[index].push_back(std::make_unique<Pipe>(type, direction, m_boardSize));

    m_pipeSys[index][m_pipeSys[index].size() - 1]->setPosition(
            {(WINDOW_WIDTH / 10) + (BOARD_WIDTH / m_boardSize.x) * (float)index,
             (WINDOW_HEIGHT / 10) + (BOARD_HEIGHT / m_boardSize.y) * ((float)m_pipeSys[index].size() - 1)});

    if (m_pipeSys[index].size() == m_boardSize.x) {
        ++index;
        if (index == m_boardSize.y)
            index = 0;
    }
}
//=============================================================================
void GameBoard::draw(sf::RenderWindow & window) {
    for(auto & pipeLine : m_pipeSys)
        for(auto & pipe : pipeLine)
            pipe->draw(window);
}
//=============================================================================
void GameBoard::rotatePipe(const sf::Event & event) {
    for(auto & pipeLine : m_pipeSys){
        for(auto & pipe : pipeLine){
            if(pipe->getSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
                if(event.mouseButton.button == sf::Mouse::Left)
                    pipe->rotateLeft();
                else if(event.mouseButton.button == sf::Mouse::Right)
                    pipe->rotateRight();
                return;
            }
        }
    }
}
//=============================================================================