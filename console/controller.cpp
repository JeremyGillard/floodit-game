#include "controller.h"

Controller::Controller(FloodIt& model, View& view)
    : m_model(model)
    , m_view(view)
{
}

void Controller::startGame()
{
    std::cout << "Let's go..." << std::endl;
}
