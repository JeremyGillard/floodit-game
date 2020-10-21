#ifndef VIEW_H
#define VIEW_H

#include <iomanip>
#include <iostream>
#include <windows.h>

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
    unsigned colorQuestion();
    void displayBoard() const;
    void endMessage() const;

private:
    FloodIt& m_model;
    unsigned m_viewHeight;
    unsigned m_viewWidth;

    void getViewDimensions();
};

#endif // VIEW_H
