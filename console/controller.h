#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "floodit.h"
#include "view.h"

#include <iostream>

class Controller {
public:
    Controller(FloodIt& model, View& view);
    void startGame();

private:
    FloodIt& m_model;
    View& m_view;

    void mainGameFlow();
};

#endif // CONTROLLER_H
