#include "controller.h"

Controller::Controller(FloodIt& model, View& view)
    : m_model(model)
    , m_view(view)
{
}

void Controller::startGame()
{
    unsigned boardWidth { 0 };
    unsigned boardHeight { 0 };
    m_view.welcomeMessage();
    if (m_view.rectangularBoardQuestion()) {
        boardHeight = m_view.sizeBoardQuestion("height");
    }
    boardWidth = m_view.sizeBoardQuestion("width");
    m_model.initBoard(boardHeight, boardWidth);
    m_model.setDifficulty(m_view.difficultyQuestion());
    mainGameFlow();
}

void Controller::mainGameFlow()
{
    while (!m_model.isOver()) {
        unsigned selectedColor = m_view.colorQuestion();
        m_model.pickColor(selectedColor);
    }
    m_view.endMessage();
    if (m_view.registerScoreQuestion()) {
        const std::string pseudo = m_view.pseudoQuestion();
        m_model.newScore(pseudo);
        m_view.showScorePanel(pseudo);
    }
}
