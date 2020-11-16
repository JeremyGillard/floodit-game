#ifndef FLOODIT_H
#define FLOODIT_H

#include <memory>
#include <stdexcept>

#include "board.h"
#include "dependencies/observer/subject.h"
#include "records.h"

/**
 * @brief The FloodIt class represents the model of this game.
 * This class inherits a Subject (Observable) class allowing
 * to put into practice the Observer/Observable design model.
 */
class FloodIt : public nvs::Subject {
public:
    /**
     * @brief FloodIt allows to create the FloodIt game. In order not to have
     * to re-instantiate a new FloodIt class for each new game in the same run,
     * the creation and use of the game board is done via other methods
     * (initBoard, setDifficulty).
     */
    FloodIt();

    /**
     * @brief initBoard allows you to initialize a game board with
     * a certain height and width (create a new game board).
     *
     * @param boardHeight the height of the board.
     * @param boardWidth the width of the board.
     */
    void initBoard(unsigned boardHeight, unsigned boardWidth);

    /**
     * @brief setDifficulty allows to determine the difficulty, the number of
     * different colors that will be placed on the game board.
     *
     * @param difficultyLevel the number of different colors that will be placed
     * on the game board.
     */
    void setDifficulty(unsigned difficultyLevel);

    /**
     * @brief isOver indicates if the game is finished or not.
     *
     * @return true if the game is over.
     */
    bool isOver() const;

    /**
     * @brief pickColor allows you to pick a certain color to play.
     * (The colors are represented by numbers for the sake of simplicity of the
     * code). If the color picked is not identical to the current flood zone color
     * then the number of moves will be increment.
     *
     * @param color the color to pick.
     */
    void pickColor(unsigned color);

    /**
     * @brief getColorAt returns the color at a certain coordinate.
     *
     * @param row the row of the coordinates.
     * @param col the column of the coordinates.
     */
    unsigned getColorAt(unsigned row, unsigned col);

    /**
     * @brief getNumberOfMoves gives the number of moves done in a given game.
     */
    unsigned getNumberOfMoves();

    /**
     * @brief chosenHeight indicates the chosen height of the game board.
     */
    unsigned chosenHeight();

    /**
     * @brief chosenWidth indicates the chosen width of the game board.
     */
    unsigned chosenWidth();

    /**
     * @brief chosenDifficulty indicates the number of color chosen for a given
     * game.
     */
    unsigned chosenDifficulty();

    /**
     * @brief newScore allows to save a new score. It can only be called when
     * a game is over and will throw an exception if it is not.
     *
     * @param pseudo the username to which the score of the last game belongs.
     */
    void newScore(const std::string& pseudo);

    /**
     * @brief getScores returns a hash map containing the scores of
     * the different players for games with the same height,
     * width and difficulty settings. It can only be called when
     * a game is over and will throw an exception if it is not.
     *
     * @return a hash map containing the scores.
     */
    std::map<unsigned, std::string> getScores() const;

    /**
     * @brief getPlayersRanking returns the player's position in the ranking
     * according to his score and a negative number if the latter is not yet
     * recorded in the scoreboard. It can only be called when
     * a game is over and will throw an exception if it is not.
     *
     * @param name the username of the player
     * (same as the one entered in newScore method).
     */
    unsigned getPlayersRanking(const std::string& name) const;

private:
    std::unique_ptr<Board> m_board;
    unsigned m_numberOfMoves;
    std::unique_ptr<Records> m_records;
};

#endif // FLOODIT_H
