#include "floodit.h"

#include <iostream>

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
}

bool FloodIt::isOver()
{
    Board board(m_board->height(), m_board->width(), m_board->getCurrentColor());
    return *m_board == board;
}

void FloodIt::pickColor(unsigned color)
{
    if (m_board->pickColor(color))
        m_numberOfMoves++;
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
