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

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void setIntroScene();
    void setGameScene();
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
