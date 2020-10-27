#ifndef FLOODIT_H
#define FLOODIT_H

#include <memory>

#include "board.h"
#include "dependencies/observer/subject.h"

class FloodIt : public nvs::Subject {
public:
    FloodIt();
    void initBoard(unsigned boardHeight, unsigned boardWidth);
    void setDifficulty(unsigned difficultyLevel);
    bool isOver();
    void pickColor(unsigned color);
    unsigned getColorAt(unsigned row, unsigned col);
    unsigned getNumberOfMoves();
    unsigned chosenHeight();
    unsigned chosenWidth();
    unsigned chosenDifficulty();

private:
    std::unique_ptr<Board> m_board;
    unsigned m_numberOfMoves;
};

#endif // FLOODIT_H
