#ifndef FLOODIT_H
#define FLOODIT_H

#include <memory>
#include <stdexcept>

#include "board.h"
#include "dependencies/observer/subject.h"
#include "records.h"

/*!
 * \mainpage Flood It
 *
 * Flood-It is a game where colored pellets are placed on a rectangular board formed by rows of c columns of locations. Let l x c pads, because no place is left empty.  
 * 
 * There are k colors of pads. At a given time, a pellet is of a given color. Initially, the color of a pellet is determined randomly. During the course of the game, the color of the tablet changes. The object of the game is to obtain a monochrome board with a minimum number of game turns.  
 * 
 * Two locations are adjacent if they are either on the same row and on adjacent columns, or on the same column and on adjacent rows. The adjacency of the locations is therefore determined only laterally, not diagonally. In other words, adjacent locations touch each other at their edges, not at their corners.  
 * 
 * Because the board is rectangular, the number of adjacent locations at a given location ranges from two, for a location in a corner of the board, to four, exceeding three, for a location at the edge of the board but not at a corner.  
 *  
 * Two dots are adjacent if they occupy adjacent locations. The dots form zones. A zone is a maximum set of adjacent pellets of the same color. A zone is a maximum set of adjacent pellets of the same color. The term maximum means that all the pellets adjacent to a zone are of a different color than the color of the zone.  
 *  
 * Two zones are adjacent whenever one pellet in
 * one zone is adjacent to a pellet in the other. 
 * 
 * During the game, a zone has a special status, the captured pellet zone, or captured zone. Initially, the captured area contains a pellet located in a corner of the game board. When the board is displayed on a vertical screen, it is usual to take this pellet in its upper left corner. 
 * 
 * The game is divided into rounds. At the beginning of each round, the player always performs the same action: he selects one of the k colors, in order to extend the captured area. Let ki be the selected color. After selecting ki, the captured area takes this color. Since an area is by definition maximum, the ki-colored areas adjacent to the captured area merge with the latter, which ideally causes its extension.  This is followed by a new turn, or the end of the game if the captured area covers the entire board.
 *
 */

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
