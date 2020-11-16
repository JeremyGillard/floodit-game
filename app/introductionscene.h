#ifndef INTRODUCTIONSCENE_H
#define INTRODUCTIONSCENE_H

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "qfloodit.h"

/**
 * @brief The IntroductionScene class allows to represent the first page of the game
 * allowing the user to choose the size of the board for the next game and its difficulty.
 */
class IntroductionScene : public QWidget {
    Q_OBJECT
public:
    /**
     * @brief IntroductionScene allows to create the first page of the game.
     * @param QFloodIt the model to display.
     * @param parent who will be in charge of its destruction.
     */
    explicit IntroductionScene(QFloodIt& qFloodIt, QWidget* parent = nullptr);

signals:
    /**
     * @brief gameIsInitialized is used to prevent that user data is selected
     * and that the game has been initiated, thus launching the game
     * and changing the page from the main window to the game page.
     */
    void gameIsInitialized();

public slots:
    /**
     * @brief initGame init the game with user Data.
     */
    void initGame();

private:
    QFloodIt* model;

    QLabel* title;
    QLabel* boardHeightLbl;
    QComboBox* boardHeightCbb;
    QLabel* boardWidthLbl;
    QComboBox* boardWidthCbb;
    QLabel* difficultyLbl;
    QComboBox* difficultyCbb;
    QPushButton* startBtn;

    QGridLayout* userInformationLayout;
    QVBoxLayout* mainLayout;

    void initComponents();

    void initUserInformationLayout();

    void arrangement();

    void behavior();
};

#endif // INTRODUCTIONSCENE_H
