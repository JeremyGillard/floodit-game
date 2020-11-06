#ifndef FLOODIT_H
#define FLOODIT_H

#include <memory>
#include <stdexcept>

#include "board.h"
#include "dependencies/observer/subject.h"
#include "records.h"

class FloodIt : public nvs::Subject {
public:
    FloodIt();
    void initBoard(unsigned boardHeight, unsigned boardWidth);
    void setDifficulty(unsigned difficultyLevel);
    bool isOver() const;
    void pickColor(unsigned color);
    unsigned getColorAt(unsigned row, unsigned col);
    unsigned getNumberOfMoves();
    unsigned chosenHeight();
    unsigned chosenWidth();
    unsigned chosenDifficulty();
    void newScore(const std::string& pseudo);
    std::map<unsigned, std::string> getScores() const;
    unsigned getPlayersRanking(const std::string& name) const;

private:
    std::unique_ptr<Board> m_board;
    unsigned m_numberOfMoves;
    std::unique_ptr<Records> m_records;
};

#endif // FLOODIT_H
