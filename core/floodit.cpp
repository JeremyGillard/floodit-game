#include "floodit.h"

FloodIt::FloodIt()
{
}

void FloodIt::initBoard(unsigned boardHeight, unsigned boardWidth)
{
    m_numberOfMoves = 0;
    if (boardHeight == 0)
        boardHeight = boardWidth;
    m_board = std::make_unique<Board>(boardHeight, boardWidth);
}

void FloodIt::setDifficulty(unsigned difficultyLevel)
{
    m_board->setDifficulty(difficultyLevel);
    notifyObservers();
}

bool FloodIt::isOver() const
{
    Board board(m_board->height(), m_board->width(), m_board->getCurrentColor());
    return *m_board == board;
}

void FloodIt::pickColor(unsigned color)
{
    if (m_board->pickColor(color)) {
        m_numberOfMoves++;
        notifyObservers();
    }
}

unsigned FloodIt::getColorAt(unsigned row, unsigned col)
{
    return m_board->getColorAt(row, col);
}

unsigned FloodIt::getNumberOfMoves()
{
    return m_numberOfMoves;
}

unsigned FloodIt::chosenHeight()
{
    return m_board->height();
}

unsigned FloodIt::chosenWidth()
{
    return m_board->width();
}

unsigned FloodIt::chosenDifficulty()
{
    return m_board->difficultyLevel();
}

void FloodIt::newScore(const std::string& pseudo)
{
    if (!isOver()) {
        throw std::logic_error("The player must have finished the game in order to register.");
    } else {
        std::string recordFileName = std::to_string(chosenHeight()) + "H_" + std::to_string(chosenWidth()) + "W_" + std::to_string(chosenDifficulty()) + "D";
        m_records = std::make_unique<Records>(recordFileName + ".csv");
        m_records->newRecord(pseudo, getNumberOfMoves());
    }
}

std::map<unsigned, std::string> FloodIt::getScores() const
{
    if (!isOver()) {
        throw std::logic_error("The player must have finished the game in order to access scores.");
    } else {
        return m_records->getScores();
    }
}

unsigned FloodIt::getPlayersRanking(const std::string& name) const
{
    if (!isOver()) {
        throw std::logic_error("The player must have finished the game in order to get his ranking.");
    } else {
        return m_records->getPlayersRanking(name);
    }
}
