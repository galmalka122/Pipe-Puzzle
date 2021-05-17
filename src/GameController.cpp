#include "GameController.h"
#include "Macros.h"

//=============================================================================
void GameController::run() {
    auto window = sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pipe");

    while (window.isOpen())
    {
        window.clear();
        m_gameBoard.draw(window);
        window.display();

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                    m_gameBoard.rotatePipe(event);
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
    }
}
//=============================================================================
void GameController::draw(sf::RenderWindow &) {

}
//=============================================================================