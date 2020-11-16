#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStackedLayout>
#include <QStyleFactory>

#include "gamescene.h"
#include "introductionscene.h"
#include "qfloodit.h"
#include "scorescene.h"

/**
 * @brief The MainWindow class is the main window of the game.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief MainWindow allows to create the main window of the game.
     * @param parent who will be in charge of its destruction.
     */
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    /**
     * @brief setIntroScene in the context of a stackedlayout,
     * allows to put the intro scene in the foreground.
     */
    void setIntroScene();

    /**
     * @brief setGameScene in the context of a stackedlayout,
     * allows to put the game scene in the foreground.
     */
    void setGameScene();

    /**
     * @brief setScoreScene in the context of a stackedlayout,
     * allows to put the score scene in the foreground.
     */
    void setScoreScene();

private:
    QFloodIt* model;

    QWidget* centralWidget;

    IntroductionScene* iScene;

    GameScene* gScene;

    ScoreScene* sScene;

    int switchSceneIndex;

    QStackedLayout* layout;

    QAction* actionNewGame;

    QAction* actionQuit;

    void initComponents();

    void arrangement();

    void behavior();

    void initMenuBar();
};
#endif // MAINWINDOW_H
