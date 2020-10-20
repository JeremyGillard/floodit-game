#ifndef VIEW_H
#define VIEW_H

#include <iomanip>
#include <iostream>

#include "dependencies/keyboard.hpp"
#include "dependencies/stringConvert.hpp"
#include "floodit.h"

class View {
public:
    View(FloodIt& model);
    void welcomeMessage();
    bool squareOrRectangularBoardQuestion();
    unsigned sizeBoardQuestion(const std::string& concernedDimension);
    unsigned difficultyQuestion();

private:
    FloodIt& m_model;
};

#endif // VIEW_H
