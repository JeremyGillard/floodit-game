#ifndef BOARD_H
#define BOARD_H

#include <random>
#include <stack>
#include <vector>

class Board {
public:
    /**
     * @brief Board built a game board with a certain author and a certain width.
     *
     * @param height the height of the board.
     * @param width the width of the board.
     * @param initializationNumber the number with which the game board is initialized.
     * It will then be replaced by the numbers chosen in the setDifficulty method.
     */
    Board(unsigned height, unsigned width, unsigned initializationNumber = 0);

    /**
     * @brief setDifficulty allows you to choose a number of colors to
     * distribute on the tray. The latter will then fill the game board with them.
     *
     * @param numberOfColor the number of color to distribute on the board.
     */
    void setDifficulty(unsigned numberOfColor);

    /**
     * @brief height returns the height of the board.
     */
    unsigned height() const;

    /**
     * @brief width returns the width of the board.
     */
    unsigned width() const;

    /**
     * @brief operator == allows to determine if two board are equal in terms of
     * disposition of colors.
     *
     * @param board the board to compare with.
     * @return true if the two board are equals.
     */
    bool operator==(const Board& board) const;

    /**
     * @brief getCurrentColor returns the color of the current flooded zone.
     * By default, this zone is determine by an origin coordinate. In this case
     * this coordiantes are 0, 0 on the board.
     */
    unsigned getCurrentColor();

    /**
     * @brief getColorAt returns the cell color at a given coordinates.
     *
     * @param row the coordinates row
     * @param col the coordinates column
     */
    unsigned getColorAt(unsigned row, unsigned col) const;

    /**
     * @brief pickColor is the main method of this game. This is the method wich
     * allows to pick a color a play the game.
     *
     * @param newColor the new color to pick.
     * @return false if the chosen color is identical to the color at the flood
     * origin coordinates.
     */
    bool pickColor(unsigned newColor);

    /**
     * @brief difficultyLevel returns the difficulty level. The number of color chosen.
     */
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
