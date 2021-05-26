#include "GameController.h"


GameController::GameController() : m_stageFile(STAGES_FILE),
                                    m_backGround(Textures::texturesObject().getSprite(BACKGROUND)){

    m_backGround.setScale(WINDOW_WIDTH / m_backGround.getGlobalBounds().width,
                          WINDOW_HEIGHT / m_backGround.getGlobalBounds().height);
}
//=============================================================================
void GameController::run() {
    auto window = sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pipe");

    // Loads the first stage.
    nextStage(window);

    while (window.isOpen()){
        window.clear();
        draw(window);
        window.display();

        // Loads the next stage.
        if (m_gameBoard.boardSolved())
            nextStage(window);

        if (auto event = sf::Event{}; window.waitEvent(event)){
            switch (event.type){
                case sf::Event::MouseButtonPressed:

                    if(m_gameBoard.rotatePipe(event)) {
                        m_stageDetail.tap(); // Counts taps.
                        Sound::soundObject().playSound(CLICK_SOUND);
                    }
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
    }
}
//=============================================================================
void GameController::draw(sf::RenderWindow & window) {
    window.draw(m_backGround);
    m_stageDetail.draw(window);
    m_gameBoard.draw(window);
}
//=============================================================================
void GameController::nextStage(sf::RenderWindow & window) {
    auto it = m_stageFile.currentIter();

    // Checks if there is no more stages.
    if(it != m_stageFile.begin()) {
        if(m_stageFile.eof()) {
            win(window, WIN_SCREEN, WIN_SOUND, WIN_SCREEN_PAUSE);
            exit(EXIT_SUCCESS);
        }
        else
            win(window, LEVEL_UP, LEVEL_UP_SOUND, LEVEL_UP_PAUSE);
    }

    m_stageDetail.initTap();
    m_stageDetail.increaseStage();

    // Gets the board size to indicate the current stage range.
    int row, col;
    auto stream = std::stringstream();
    stream << m_stageFile.getLine();
    if(!(stream >> col >> row))
        throw std::invalid_argument("An issue occurred while reading the game board size from the file");

    m_gameBoard.nextStage(it, it + row * col + 1);

    // Initialize the iterator to the line of the next stage.
    m_stageFile.next(row * col + 2);
}
//=============================================================================
void GameController::win(sf::RenderWindow & window,
                         const enum Textures_t enumTextures,
                         const enum Sounds_t enumSounds,
                                 int pause) {

    auto winScreen = Textures::texturesObject().getSprite(enumTextures);
    winScreen.setScale(WINDOW_WIDTH / winScreen.getGlobalBounds().width,
                       WINDOW_HEIGHT / winScreen.getGlobalBounds().height);
    window.clear();
    window.draw(winScreen);
    window.display();

    Sound::soundObject().playSound(enumSounds);

    sf::sleep(sf::seconds(pause));

    auto event = sf::Event{};
    while (window.pollEvent(event));
}
//=============================================================================