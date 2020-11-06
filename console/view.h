#ifndef VIEW_H
#define VIEW_H

#include <iomanip>
#include <iostream>
#include <windows.h>

#include "dependencies/keyboard.hpp"
#include "dependencies/observer/observer.h"
#include "dependencies/stringConvert.hpp"
#include "floodit.h"

class View : public nvs::Observer {
public:
    View(FloodIt& model);
    ~View();
    void welcomeMessage();
    bool squareOrRectangularBoardQuestion();
    unsigned sizeBoardQuestion(const std::string& concernedDimension);
    unsigned difficultyQuestion();
    unsigned colorQuestion();
    void displayBoard() const;
    void endMessage() const;
    bool registerScoreQuestion() const;
    std::string pseudoQuestion() const;
    void showScorePanel(const std::string& pseudo) const;
    virtual void update(const nvs::Subject* subject) override;

private:
    FloodIt& m_model;
    unsigned m_viewHeight;
    unsigned m_viewWidth;

    void getViewDimensions(); // Pour éventuellement avoir une plus belle représentation console
};

#endif // VIEW_H
