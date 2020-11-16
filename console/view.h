#ifndef VIEW_H
#define VIEW_H

#include <iomanip>
#include <iostream>
#include <windows.h>

#include "dependencies/keyboard.hpp"
#include "dependencies/observer/observer.h"
#include "dependencies/stringConvert.hpp"
#include "floodit.h"

/**
 * @brief The View class allows to display the game FloodIt in the standard console.
 * This class inherits from an Observer class allowing the Observer/Observable
 * design model to be put into practice.
 */
class View : public nvs::Observer {
public:
    /**
     * @brief View allows to create a view for the game FloodIt.
     *
     * @param model the teasing game to be represented.
     */
    View(FloodIt& model);
    ~View();

    /**
     * @brief welcomeMessage allows to display a welcome/introduction message.
     */
    void welcomeMessage();

    /**
     * @brief rectangularBoardQuestion asks the user if he wants to play
     * on a square or rectangular game board.
     *
     * @return true if the user wants to play on a rectangular board.
     */
    bool rectangularBoardQuestion();

    /**
     * @brief sizeBoardQuestion allows you to ask a question about a dimension
     * of the game board.
     *
     * @param concernedDimension the name of the concerned dimension.
     */
    unsigned sizeBoardQuestion(const std::string& concernedDimension);

    /**
     * @brief difficultyQuestion allows to ask to the user the difficulty of the game.
     * The number of colors to distribute on the board.
     */
    unsigned difficultyQuestion();

    /**
     * @brief colorQuestion allows to ask the gameplay question to the user.
     */
    unsigned colorQuestion();

    /**
     * @brief displayBoard allows to display the game board.
     */
    void displayBoard() const;

    /**
     * @brief endMessage allows to display an end message with the total number
     * of moves.
     */
    void endMessage() const;

    /**
     * @brief registerScoreQuestion allows to ask if the user wants to register
     * his score.
     *
     * @return true if the user wants to register his score.
     */
    bool registerScoreQuestion() const;

    /**
     * @brief pseudoQuestion allows to ask the username of the current user.
     *
     * @return the username entered by the user.
     */
    std::string pseudoQuestion() const;

    /**
     * @brief showScorePanel allows to display the score panel as well as the
     * position of a given pseudo entered.
     *
     * @param pseudo the nickname whose place must be displayed in the scoreboard.
     */
    void showScorePanel(const std::string& pseudo) const;

    /**
     * @brief update is a method inherited by the Observer class allowing to use
     * the Observer/Observable pattern.
     *
     * @param subject the subject (obervable) to update.
     */
    virtual void update(const nvs::Subject* subject) override;

private:
    FloodIt& m_model;
};

#endif // VIEW_H
