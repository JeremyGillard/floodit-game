#ifndef BOARD_H
#define BOARD_H

#include <random>
#include <stack>
#include <vector>

class Board {
public:
    Board(unsigned height, unsigned width, unsigned initializationNumber = 0);
    void setDifficulty(unsigned numberOfColor);
    unsigned height() const;
    unsigned width() const;
    bool operator==(const Board& board) const;
    unsigned getCurrentColor();
    unsigned getColorAt(unsigned row, unsigned col) const;
    bool pickColor(unsigned newColor);
    unsigned difficultyLevel();

private:
    unsigned m_height;
    unsigned m_width;
    unsigned m_difficultyLevel;
    std::pair<unsigned, unsigned> m_floodOrigin;
    std::vector<std::vector<unsigned>> m_board;

    void flood(std::stack<std::pair<unsigned, unsigned>>& job, unsigned oldColor, unsigned newColor);
};

#endif // BOARD_H
