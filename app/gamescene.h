#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QDir>
#include <QGridLayout>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QWidget>

#include "cell.h"
#include "qfloodit.h"

/**
 * @brief The GameScene class allows to display the game board and play with it.
 */
class GameScene : public QWidget {
    Q_OBJECT
public:
    /**
     * @brief GameScene allows to create a game scene that allows the player
     * to play with the game FloodIt.
     *
     * @param qFloodIt the floodit that will be represented.
     * @param parent parent who will be in charge of its destruction.
     */
    explicit GameScene(QFloodIt& qFloodIt, QWidget* parent = nullptr);

signals:
    /**
     * @brief newGameConfirmation signal when a player decides to start
     * a new game without having finished the previous one.
     */
    void newGameConfirmation();

    /**
     * @brief registerScoreConfirmation allows to display the final score scene
     * after a user score registration.
     */
    void registerScoreConfirmation();

public slots:
    void initBoard();
    void updateBoard();
    void finalBoard();
    void newGame();
    void registerScore();

private:
    QFloodIt* model;
    QLabel* progressLbl;
    QWidget* boardWidget;
    QGridLayout* boardLayout;
    QPushButton* newGameBtn;
    QPushButton* registerScoreBtn;
    QVBoxLayout* mainLayout;

    void initComponents();
    void clearComponents();
    void arrangement();
    void behavior();
};

#endif // GAMESCENE_H
