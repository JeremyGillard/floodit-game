#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "floodit.h"
#include "view.h"

/**
 * @brief The Controller class allows to orchestrate user interactions/views
 * view with the FloodIt model.
 */
class Controller {
public:
    /**
     * @brief Controller Controller allows to create a controller that will
     * orchestrate user interactions/views view with the FloodIt model.
     *
     * @param model the FloodIt which will have to be linked to the view.
     * @param view the view that will have to be linked to the FloodIt.
     */
    Controller(FloodIt& model, View& view);

    /**
     * @brief startGame allows to start the game.
     */
    void startGame();

private:
    FloodIt& m_model;
    View& m_view;

    void mainGameFlow();
};

#endif // CONTROLLER_H
